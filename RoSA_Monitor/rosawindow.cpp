#include "rosawindow.h"
#include "ui_rosawindow.h"

RosaWindow::RosaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RosaWindow), numOfTabs(2)//2 cuando este hecho el tab debug
{
    ui->setupUi(this);

    for(int i = 0; i < LauncherManager::NUMBER_OF_LAUNCHERS; i++)
    {
        tab_Index[i] = 0;
        shellWindows[i] = nullptr;
    }
}

RosaWindow::~RosaWindow()
{
    for(int i = 0; i < LauncherManager::NUMBER_OF_LAUNCHERS; i++)
    {
        if(shellWindows[i] != nullptr)
        {
            delete shellWindows[i];
        }
    }
    delete ui;
}


/****************************************************
*               EXTERNAL FUNCTIONS                  *
****************************************************/
void RosaWindow::closeEvent(QCloseEvent *event)
{
    //If any process is running ask user if stop them
    if(manager.IsAnyActive())
    {
        int disclaimer = QMessageBox::warning(this, tr("RoSA Shutdown"), tr("Are you sure you want to close?\nIt will shutdown all active processes"),
                                              QMessageBox::Yes | QMessageBox::No);

        //stop all processes
        if (disclaimer == QMessageBox::Yes)
        {
            running = false;
            manager.ShutdownLaunchers();
            emit windowClosed();
            event->accept();
        }
        //Do not stop neither close the window
        else
        {
            running = true;
            event->ignore();
        }
    }
    //If no processes running close the wondow
    else
    {
        emit windowClosed();
        event->accept();
    }
}


void RosaWindow::SetWorkspace(QString w_path)
{
    manager.SetWorkspaceDir(w_path);
}

QDir* RosaWindow::getWorkspace()
{
    return manager.GetWorkspacePath();
}


/****************************************************
*               SLOT FUNCTIONS                      *
****************************************************/

void RosaWindow::on_firmwareButton_clicked()
{
    if(ButtonPressed(ui->firmwareButton, LauncherManager::FIRMWARE, "Firmware"))
    {
        qDebug()<<"Firmware correctly executed";
    }
    else
    {
        qDebug()<<"Error executing RoSA firmware  ";
        ui->firmwareButton->setChecked(false);

    }
}


void RosaWindow::on_URDFButton_clicked()
{
    if(ButtonPressed(ui->URDFButton, LauncherManager::URDF, "URDF"))
    {
        qDebug()<<"Firmware correctly executed";
    }
    else
    {
        qDebug()<<"Error executing RoSA URDF  ";
        ui->URDFButton->setChecked(false);

    }
}

void RosaWindow::on_lidarButton_clicked()
{
    if(ButtonPressed(ui->lidarButton, LauncherManager::LIDAR, "Hokuyo LiDAR"))
    {
        qDebug()<<"Firmware correctly executed";
    }
    else
    {
        qDebug()<<"Error executing RoSA LiDAR  ";
        ui->lidarButton->setChecked(false);

    }
}


void RosaWindow::on_SlamButton_clicked()
{
    if(!manager.GetLauncher(LauncherManager::SLAM_SIM)->GetActive())
    {
        QuestionRvizClose(ui->RvizzButton);
        if(!FirstLaunchFirmware(ui->SlamButton))
        {
            return;
        }
        else
        {
            //If this process is executing do not duplicate
            if (manager.GetLauncher(LauncherManager::SLAM_SIM)->GetLauncherProcess() != nullptr)
            {
                qDebug() << "Process already executing.";
                return;
            }
            //Create new process
            if(!manager.CreateLauncher(LauncherManager::SLAM_SIM, new QProcess(this)))
            {
                return;
            }
            else
            {
                //Create shell window and connect shell output of process launcher to the read output slot
                shellWindows[LauncherManager::SLAM_SIM] = new ShellOutputWindow(this, manager.GetLauncher(LauncherManager::SLAM_SIM)->GetLauncherProcess());
                connect(manager.GetLauncher(LauncherManager::SLAM_SIM)->GetLauncherProcess(), &QProcess::readyReadStandardOutput, shellWindows[LauncherManager::SLAM_SIM], &ShellOutputWindow::readProcessOutput);

                //Run the process
                manager.Launch(LauncherManager::SLAM_SIM);
                ui->SlamButton->setChecked(true);
                ui->SlamButton->setText("Stop SLAM");

                //Add new tab
                ui->tabRoSAWidget->addTab(shellWindows[LauncherManager::SLAM_SIM], "SLAM shell");
                tab_Index[LauncherManager::SLAM_SIM] = numOfTabs++;
            }
        }

    }
    //Stop the process due to a second press on button
    else
    {
        ui->SlamButton->setText("Run SLAM");
        manager.StopLauncher(LauncherManager::SLAM_SIM);
        ui->SlamButton->setChecked(false);

        //Delete tab
        shellWindows[LauncherManager::SLAM_SIM] = nullptr;
        RemoveTab(LauncherManager::SLAM_SIM);
    }
}


void RosaWindow::on_navigationButton_clicked()
{
    //Check if SLAM is active
    if(manager.GetLauncher(LauncherManager::SLAM_SIM)->GetActive())
    {
        QMessageBox::information(this, tr("RoSA Info"), tr("Can not open navigation while mapping"));
        ui->navigationButton->setChecked(false);
        return;
    }
    if(!manager.GetLauncher(LauncherManager::NAVIGATION)->GetActive())
    {
        QuestionRvizClose(ui->RvizzButton);
        if(!FirstLaunchFirmware(ui->navigationButton))
        {
            return;
        }
        else
        {
            //If this process is executing do not duplicate
            if (manager.GetLauncher(LauncherManager::NAVIGATION)->GetLauncherProcess() != nullptr)
            {
                qDebug() << "Process already executing.";
                return;
            }

            //If no map is selected ask user for it
            if(manager.GetMap()==nullptr)
            {
                QString map_name = "";
                QMessageBox::information(this, tr("RoSA Info"), tr("Select your .yaml map"));
                map_name= QFileDialog::getOpenFileName(this, "Select your map", manager.GetWorkspacePath()->path() + "/maps", tr("maps (*.yaml)"));

                //If no map selected cancel launch
                if(map_name.isEmpty())
                {
                    ui->navigationButton->setChecked(false);
                    return;
                }
                else
                {
                    manager.SetMap(map_name);
                    QFileInfo mapInfo(*manager.GetMap());
                    ui->mapLabel->setText(mapInfo.fileName());
                }
            }
            //Create new process
            if(!manager.CreateLauncher(LauncherManager::NAVIGATION, new QProcess(this)))
            {
                return;
            }
            else
            {
                //Create shell window and connect shell output of process launcher to the read output slot
                shellWindows[LauncherManager::NAVIGATION] = new ShellOutputWindow(this, manager.GetLauncher(LauncherManager::NAVIGATION)->GetLauncherProcess());
                connect(manager.GetLauncher(LauncherManager::NAVIGATION)->GetLauncherProcess(), &QProcess::readyReadStandardOutput, shellWindows[LauncherManager::NAVIGATION], &ShellOutputWindow::readProcessOutput);

                //Launch process
                manager.Launch(LauncherManager::NAVIGATION);
                ui->navigationButton->setChecked(true);
                ui->navigationButton->setText("Stop Navigation");

                //Add new tab
                ui->tabRoSAWidget->addTab(shellWindows[LauncherManager::NAVIGATION], "Navigation shell");
                tab_Index[LauncherManager::NAVIGATION] = numOfTabs++;
            }
        }

    }
    //Stop process
    else
    {
        ui->navigationButton->setText("Run Navigation");
        manager.StopLauncher(LauncherManager::NAVIGATION);
        ui->navigationButton->setChecked(false);

        //Delete tab
        shellWindows[LauncherManager::NAVIGATION] = nullptr;
        RemoveTab(LauncherManager::NAVIGATION);
    }
}




void RosaWindow::on_RvizzButton_clicked()
{
    if(ButtonPressed(ui->RvizzButton, LauncherManager::RVIZZ2, "Rviz2"))
    {
        qDebug()<<"Button Rviz2 correctly executed";
    }
    else
    {
        qDebug()<<"Error executing Rviz2  ";
        ui->RvizzButton->setChecked(false);

    }
}

void RosaWindow::on_graphButton_clicked()
{
    if(ButtonPressed(ui->graphButton, LauncherManager::RQT_GRAPH, "rqt_graph"))
    {
        qDebug()<<"Button rqt_graph correctly executed";
    }
    else
    {
        qDebug()<<"Error executing rqt_graph  ";
        ui->graphButton->setChecked(false);

    }
}


void RosaWindow::on_rqtButton_clicked()
{
    if(ButtonPressed(ui->rqtButton, LauncherManager::RQT, "rqt"))
    {
        qDebug()<<"Button rqt correctly executed";
    }
    else
    {
        qDebug()<<"Error executing rqt  ";
        ui->rqtButton->setChecked(false);

    }
}


void RosaWindow::on_viewFramesButton_clicked()
{
    QDir* directory;
    QDir* wsBackup;

    //Set workspace first
    if(manager.GetWorkspacePath()==nullptr)
    {
        QMessageBox::information(this, tr("RoSA Info"), tr("You have to select a ROS2 workspace first"));
        QString workspace_name = "";
        while(workspace_name =="")
        {
            workspace_name= QFileDialog::getExistingDirectory(this, "Select your workspace", QDir::homePath(), QFileDialog::ShowDirsOnly);
        }
        SetWorkspace(workspace_name);

        //Verify if /maps exists
        QString mapsDirPath = manager.GetWorkspacePath()->filePath("maps");
        bool mapsExist = manager.GetWorkspacePath()->exists("maps");

        //If not, create /maps in workspace
        if (!mapsExist)
        {
            manager.GetWorkspacePath()->mkpath(mapsDirPath);
        }
    }

    //Select directory to save files
    QMessageBox::information(this, tr("RoSA Info"), tr("Select directory to save transform tree"));
    QString dirName= QFileDialog::getExistingDirectory(this, "Select directory to save transform tree", QDir::homePath(), QFileDialog::ShowDirsOnly);
    if(dirName == "")
    {
        return;
    }
    else
    {
        //Create QDir and save current workspace directory in a backup
        directory = new QDir(dirName);
        wsBackup = manager.GetWorkspacePath();
    }

    if(!manager.GetLauncher(LauncherManager::VIEW_FRAMES)->GetActive())
    {
        //If this process is executing do not duplicate
        if (manager.GetLauncher(LauncherManager::VIEW_FRAMES)->GetLauncherProcess() != nullptr)
        {
            qDebug() << "Process already executing.";
            delete directory;
            return;
        }

        //Change working directory to save file path
        manager.SetWorkspaceDir(directory->path());

        //Create new process
        if(!manager.CreateLauncher(LauncherManager::VIEW_FRAMES, new QProcess(this)))
        {
            //If process fail restore workspace
            manager.SetWorkspaceDir(wsBackup->path());
            delete directory;
            return;
        }
        else
        {
            //Execute and restore workspace
            manager.Launch(LauncherManager::VIEW_FRAMES);
            manager.SetWorkspaceDir(wsBackup->path());
            manager.setActive(false, LauncherManager::VIEW_FRAMES);

            delete directory;
            return;
        }
    }
    delete directory;
}


void RosaWindow::on_TeleopButton_clicked()
{
    if(ButtonPressed(ui->TeleopButton, LauncherManager::TELEOP, "teleop_twist"))
    {
        qDebug()<<"Button rqt correctly executed";
    }
    else
    {
        qDebug()<<"Error executing teleop  ";
        ui->TeleopButton->setChecked(false);

    }
}


void RosaWindow::on_selectMapButton_clicked()
{
    //Ask for a map file
    QString map_name = "";
    QString openedDirectory= manager.GetWorkspacePath() == nullptr? "/home" : manager.GetWorkspacePath()->path() + "/maps";
    map_name= QFileDialog::getOpenFileName(this, "Select your map", openedDirectory, tr("maps (*.yaml)"));

    if(map_name.isEmpty())
    {
        return;
    }
    else
    {
        manager.SetMap(map_name);
        QFileInfo mapInfo(*manager.GetMap());
        ui->mapLabel->setText(mapInfo.fileName());
    }
}

void RosaWindow::on_mainMenuButton_clicked()
{
    //Hide the window to show main menu
    this->hide();
}
void RosaWindow::on_mainMenuButton_2_clicked()
{
    on_mainMenuButton_clicked();
}



/****************************************************
*               INTERNAL FUNCTIONS                  *
****************************************************/

bool RosaWindow::ButtonPressed(QPushButton* button, LauncherManager::LauncherType type, QString name)
{
    //Ask user for a workspace if not selected yet
    if(manager.GetWorkspacePath()==nullptr)
    {
        QMessageBox::information(this, tr("RoSA Info"), tr("You have to select a ROS2 workspace first"));
        QString workspace_name = "";

        workspace_name= QFileDialog::getExistingDirectory(this, "Select your workspace", QDir::homePath(), QFileDialog::ShowDirsOnly);
        if(workspace_name == "")
        {
            return false;
        }
        SetWorkspace(workspace_name);

        //Verify if /maps exists
        QString mapsDirPath = manager.GetWorkspacePath()->filePath("maps");
        bool mapsExist = manager.GetWorkspacePath()->exists("maps");

        //If not, create /maps in workspace
        if (!mapsExist)
        {
            manager.GetWorkspacePath()->mkpath(mapsDirPath);
        }
    }
    if(!manager.GetLauncher(type)->GetActive())
    {
        //If this process is executing do not duplicate
        if (manager.GetLauncher(type)->GetLauncherProcess() != nullptr)
        {
            qDebug() << "Process already executing.";
            return false;
        }

        //Create new process
        if(!manager.CreateLauncher(type, new QProcess(this)))
        {
            return false;
        }
        else
        {
            //Create shell window and connect shell output of process launcher to the read output slot
            shellWindows[type] = new ShellOutputWindow(this, manager.GetLauncher(type)->GetLauncherProcess());
            connect(manager.GetLauncher(type)->GetLauncherProcess(), &QProcess::readyReadStandardOutput, shellWindows[type], &ShellOutputWindow::readProcessOutput);

            //Launch process
            manager.Launch(type);
            button->setChecked(true);
            button->setText("Stop " + name);

            //Add new tab
            ui->tabRoSAWidget->addTab(shellWindows[type], name + " shell");
            tab_Index[type] = numOfTabs++;
            return true;
        }
    }
    else
    {
        button->setText("Run " + name);
        manager.StopLauncher(type);
        button->setChecked(false);

        //Delete tab
        shellWindows[type] = nullptr;
        RemoveTab(type);

        return true;
    }
}


void RosaWindow::QuestionRvizClose(QPushButton *buttonClicked)
{
    if(manager.GetLauncher(LauncherManager::RVIZZ2)->GetActive()){
        int disclaimer = QMessageBox::question(this, tr("RoSA Question"), tr("This button opens a custom Rvizz2\nDo you want to close the openned one?"),
                                              QMessageBox::Yes | QMessageBox::No);
        if(disclaimer == QMessageBox::Yes){
            manager.StopLauncher(LauncherManager::RVIZZ2);
            buttonClicked->setChecked(false);
            ui->RvizzButton->setText("Run Rvizz2");
        }
    }
}

bool RosaWindow::FirstLaunchFirmware(QPushButton* buttonClicked)
{
    if(!manager.GetLauncher(LauncherManager::GAZEBO_SIM)->GetActive())
    {
        int disclaimer = QMessageBox::question(this, tr("RoSA Question"), tr("First you need to start RoSA Firmware\nLaunch Gazebo?"));
        if(disclaimer == QMessageBox::No)
        {
            buttonClicked->setChecked(false);
            return false;
        }
        else
        {
            on_firmwareButton_clicked();
        }
    }
    return true;
}

void RosaWindow::RemoveTab(LauncherManager::LauncherType type)
{
    //Delete tab
    ui->tabRoSAWidget->removeTab(tab_Index[type]);
    numOfTabs--;

    //Update index of tab_Index[]
    for(int i = 0; i < LauncherManager::NUMBER_OF_LAUNCHERS; i++)
    {
        if(tab_Index[i] > tab_Index[type])
        {
            tab_Index[i]--;
        }
    }

    tab_Index[type] = 0;
}

