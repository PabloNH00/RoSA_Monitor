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

    ui->selectMapButton->setStyleSheet("QPushButton {"
                                       "font-family: 'Times New Roman';"
                                       "font-size: 18px;"
                                       "font-weight: bold;"
                                       "border-color: red;"
                                       "background-color: lightcoral;"
                                       "border-radius: 5px; "
                                      "padding: 10px 20px; "
                                       "color: black; "
                                   "}");
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
        int disclaimer = QMessageBox::warning(this, tr("ROSA Shutdown"), tr("Are you sure you want to close?\nIt will shutdown all active processes"),
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
void RosaWindow::on_rosaButton_clicked()
{
    if(manager.GetLauncher(LauncherManager::FIRMWARE)->GetActive() ||
       manager.GetLauncher(LauncherManager::LIDAR)->GetActive()    ||
       manager.GetLauncher(LauncherManager::URDF)->GetActive())
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("For a clean launch first stop components running or use below buttons to activate individual components"));
        ui->statusbar->showMessage("First stop all components", 5000);
        return;
    }

    //Open checkbox window with components
    SelectRosaComponents selectWindow(this);
    if (selectWindow.exec() == QDialog::Accepted)
    {
       QList<QCheckBox*> selectedCheckBoxes = selectWindow.getSelectedComponents();

       //Launch checked components
       for (QCheckBox *checkBox : selectedCheckBoxes)
       {
           if(checkBox->isChecked())
           {
               if(checkBox->objectName() == "firmwareCheckbox")
               {
                    on_firmwareButton_clicked();
               }
               if(checkBox->objectName() == "urdfCheckbox")
               {
                    on_URDFButton_clicked();
               }
               if(checkBox->objectName() == "lidarCheckbox")
               {
                    on_lidarButton_clicked();
               }
               if(checkBox->objectName() == "cameraCheckbox")
               {
                    on_cameraButton_clicked();
               }
           }
       }

       UpdateNodeList();

    }
}


void RosaWindow::on_firmwareButton_clicked()
{
    if(ButtonPressed(ui->firmwareButton, LauncherManager::FIRMWARE, "Odom"))
    {
        qDebug()<<"Odom from Firmware correctly executed";
    }
    else
    {
        qDebug()<<"Error executing Odom from Firmware";
        ui->firmwareButton->setChecked(false);

    }
}


void RosaWindow::on_URDFButton_clicked()
{
    if(ButtonPressed(ui->URDFButton, LauncherManager::URDF, "URDF"))
    {
        qDebug()<<"URDF executed";
    }
    else
    {
        qDebug()<<"Error executing ROSA URDF  ";
        ui->URDFButton->setChecked(false);

    }
}

void RosaWindow::on_lidarButton_clicked()
{
    if(ButtonPressed(ui->lidarButton, LauncherManager::LIDAR, "LiDAR"))
    {
        qDebug()<<"LiDAR correctly executed";
    }
    else
    {
        qDebug()<<"Error executing ROSA LiDAR  ";
        ui->lidarButton->setChecked(false);

    }
}

void RosaWindow::on_cameraButton_clicked()
{
    if(ButtonPressed(ui->cameraButton, LauncherManager::CAMERA, "Camera"))
    {
        qDebug()<<"Camera correctly executed";
    }
    else
    {
        qDebug()<<"Error executing RGBD Camera";
        ui->cameraButton->setChecked(false);

    }
}

void RosaWindow::on_SlamButton_clicked()
{
    //Check if navigation is active
    if(manager.GetLauncher(LauncherManager::NAVIGATION)->GetActive())
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("Can not open SLAM while navigating"));
        ui->SlamButton->setChecked(false);

        ui->statusbar->showMessage("Close navigation before launch SLAM", 5000);

        return;
    }
    if(!manager.GetLauncher(LauncherManager::SLAM)->GetActive())
    {
        QuestionRvizClose(ui->RvizzButton);
        if(!FirstLaunchFirmware(ui->SlamButton))
        {
            return;
        }
        else
        {
            //If this process is executing do not duplicate
            if (manager.GetLauncher(LauncherManager::SLAM)->GetLauncherProcess() != nullptr)
            {
                ui->statusbar->showMessage("Process SLAM already executing", 5000);
                return;
            }
            //Create new process
            if(!manager.CreateLauncher(LauncherManager::SLAM, new QProcess(this)))
            {
                ui->statusbar->showMessage("Launch failed", 5000);

                return;
            }
            else
            {
                //Create shell window and connect shell output of process launcher to the read output slot
                shellWindows[LauncherManager::SLAM] = new ShellOutputWindow(this, manager.GetLauncher(LauncherManager::SLAM)->GetLauncherProcess());
                connect(manager.GetLauncher(LauncherManager::SLAM)->GetLauncherProcess(), &QProcess::readyReadStandardOutput, shellWindows[LauncherManager::SLAM], &ShellOutputWindow::readProcessOutput);

                //Run the process
                manager.Launch(LauncherManager::SLAM);
                ui->SlamButton->setChecked(true);
                ui->SlamButton->setText("Stop SLAM");

                ui->statusbar->showMessage("Launching SLAM", 5000);

                //Add new tab
                ui->tabRoSAWidget->addTab(shellWindows[LauncherManager::SLAM], "SLAM shell");
                tab_Index[LauncherManager::SLAM] = numOfTabs++;
            }
        }

        UpdateNodeList();

    }
    //Stop the process due to a second press on button
    else
    {
        ui->SlamButton->setText("Run SLAM");
        manager.StopLauncher(LauncherManager::SLAM);
        ui->SlamButton->setChecked(false);

        ui->statusbar->showMessage("Stopping SLAM", 5000);

        //Delete tab
        shellWindows[LauncherManager::SLAM] = nullptr;
        RemoveTab(LauncherManager::SLAM);

        UpdateNodeList();
    }
}


void RosaWindow::on_navigationButton_clicked()
{
    //Check if SLAM is active
    if(manager.GetLauncher(LauncherManager::SLAM)->GetActive())
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("Can not open navigation while mapping"));
        ui->navigationButton->setChecked(false);

        ui->statusbar->showMessage("Close SLAM before launch navigation", 5000);

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
                ui->statusbar->showMessage("Process Navigation already executing", 5000);
                return;
            }

            //If no map is selected ask user for it
            if(manager.GetMap()==nullptr)
            {
                QString map_name = "";
                QMessageBox::information(this, tr("ROSA Info"), tr("Select your .yaml map"));
                map_name= QFileDialog::getOpenFileName(this, "Select your map", manager.GetWorkspacePath()->path() + "/maps", tr("maps (*.yaml)"));

                //If no map selected cancel launch
                if(map_name.isEmpty())
                {
                    ui->statusbar->showMessage("No map selected, launch aborted", 5000);

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
                ui->statusbar->showMessage("Launch failed", 5000);

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

                ui->statusbar->showMessage("Launching Navigation", 5000);

                //Add new tab
                ui->tabRoSAWidget->addTab(shellWindows[LauncherManager::NAVIGATION], "Navigation shell");
                tab_Index[LauncherManager::NAVIGATION] = numOfTabs++;
            }

            UpdateNodeList();
        }

    }
    //Stop process
    else
    {
        ui->navigationButton->setText("Run Navigation");
        manager.StopLauncher(LauncherManager::NAVIGATION);
        ui->navigationButton->setChecked(false);

        ui->statusbar->showMessage("Stopping Navigation", 5000);

        //Delete tab
        shellWindows[LauncherManager::NAVIGATION] = nullptr;
        RemoveTab(LauncherManager::NAVIGATION);

        UpdateNodeList();
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
        QMessageBox::information(this, tr("ROSA Info"), tr("You have to select a ROS2 workspace first"));
        QString workspace_name = "";

        workspace_name= QFileDialog::getExistingDirectory(this, "Select your workspace", QDir::homePath(), QFileDialog::ShowDirsOnly);

        if(workspace_name == "")
        {
            ui->statusbar->showMessage("No workspace selected", 5000);
            return;
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
    QMessageBox::information(this, tr("ROSA Info"), tr("Select directory to save transform tree"));
    QString dirName= QFileDialog::getExistingDirectory(this, "Select directory to save transform tree", QDir::homePath(), QFileDialog::ShowDirsOnly);
    if(dirName == "")
    {
        ui->statusbar->showMessage("No valid directory", 5000);

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
        qDebug()<<"Button teleop correctly executed";
    }
    else
    {
        qDebug()<<"Error executing teleop  ";
        ui->TeleopButton->setChecked(false);

    }
}

void RosaWindow::on_esp32Button_clicked()
{
    if(ButtonPressed(ui->esp32Button, LauncherManager::ESP32, "ESP32 monitor"))
    {
        qDebug()<<"Button ESP32 correctly executed";
    }
    else
    {
        qDebug()<<"Error executing esp32";
        ui->esp32Button->setChecked(false);

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
        ui->statusbar->showMessage("No map selected", 5000);
        return;
    }
    else
    {
        manager.SetMap(map_name);
        QFileInfo mapInfo(*manager.GetMap());
        ui->mapLabel->setText(mapInfo.fileName());

        ui->selectMapButton->setStyleSheet("QPushButton {"
                                           "font-family: 'Times New Roman';"
                                           "font-size: 18px; "
                                           "font-weight: bold;"
                                           "border: 2px solid #ccc;"
                                           "border-radius: 5px;"
                                          "padding: 10px 20px;"
                                           "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 white, stop:1 #f0f0f0);"
                                           "color: black; "
                                       "}");
    }
}

void RosaWindow::on_mainMenuButton_clicked()
{
    // Emit signal to main window to update workspace
    emit showMainWindow();

    //Hide the window to show main menu
    this->hide();
}
void RosaWindow::on_mainMenuButton_2_clicked()
{
    on_mainMenuButton_clicked();
}

void RosaWindow::on_nodeListButton_clicked()
{
    //Ask user for a workspace if not selected yet
    if(manager.GetWorkspacePath()==nullptr)
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("You have to select a ROS2 workspace first"));
        QString workspace_name = "";

        workspace_name= QFileDialog::getExistingDirectory(this, "Select your workspace", QDir::homePath(), QFileDialog::ShowDirsOnly);
        if(workspace_name == "")
        {
            ui->statusbar->showMessage("No workspace selected", 5000);
            return;
        }
        SetWorkspace(workspace_name);

        //Verify if /maps exists
        QString mapsDirPath = manager.GetWorkspacePath()->filePath("maps");
        bool mapsExist = manager.GetWorkspacePath()->exists("maps");

        //If not, create /maps in workspace
        if (!mapsExist)
        {
            manager.GetWorkspacePath()->mkpath(mapsDirPath);
            ui->statusbar->showMessage("Maps folder created", 5000);
        }
    }
    if(manager.GetLauncher(LauncherManager::NODE_LIST)->GetActive())
    {
        manager.StopLauncher(LauncherManager::NODE_LIST);
    }
    //Create new process
    if(!manager.CreateLauncher(LauncherManager::NODE_LIST, new QProcess(this)))
    {
        ui->statusbar->showMessage("Launch failed", 5000);
        return;
    }
    else
    {
            //if first time launched create new tab
        if(shellWindows[LauncherManager::NODE_LIST] == nullptr)
        {
            //Create shell window and connect shell output of process launcher to the read output slot
            shellWindows[LauncherManager::NODE_LIST] = new ShellOutputWindow(this, manager.GetLauncher(LauncherManager::NODE_LIST)->GetLauncherProcess());
            //Add new tab
            ui->tabRoSAWidget->addTab(shellWindows[LauncherManager::NODE_LIST], "ROS2 node list");
            tab_Index[LauncherManager::NODE_LIST] = numOfTabs++;

            ui->nodeListButton->setText("Update ROS2 node list");
        }
        //if not first time clear tab and associates the new process
        else
        {
            shellWindows[LauncherManager::NODE_LIST]->ClearText();
            shellWindows[LauncherManager::NODE_LIST]->setLauncherProcess(manager.GetLauncher(LauncherManager::NODE_LIST)->GetLauncherProcess());
        }
        connect(manager.GetLauncher(LauncherManager::NODE_LIST)->GetLauncherProcess(), &QProcess::readyReadStandardOutput, shellWindows[LauncherManager::NODE_LIST], &ShellOutputWindow::readProcessOutput);

        //Launch process
        manager.Launch(LauncherManager::NODE_LIST);

        ui->statusbar->showMessage("Launching node list", 5000);
    }
}




/****************************************************
*               INTERNAL FUNCTIONS                  *
****************************************************/

bool RosaWindow::ButtonPressed(QPushButton* button, LauncherManager::LauncherType type, QString name)
{
    //Ask user for a workspace if not selected yet
    if(manager.GetWorkspacePath()==nullptr)
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("You have to select a ROS2 workspace first"));
        QString workspace_name = "";

        workspace_name= QFileDialog::getExistingDirectory(this, "Select your workspace", QDir::homePath(), QFileDialog::ShowDirsOnly);
        if(workspace_name == "")
        {
            ui->statusbar->showMessage("No workspace selected", 5000);

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
            ui->statusbar->showMessage("Process " + name + " already executing", 5000);
            return false;
        }

        //Create new process
        if(!manager.CreateLauncher(type, new QProcess(this)))
        {
            ui->statusbar->showMessage("Launch failed", 5000);
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

            ui->statusbar->showMessage("Launching " + name, 5000);

            //Add new tab
            ui->tabRoSAWidget->addTab(shellWindows[type], name + " shell");
            tab_Index[type] = numOfTabs++;

            UpdateNodeList();

            return true;
        }
    }
    else
    {
        button->setText("Run " + name);
        manager.StopLauncher(type);
        button->setChecked(false);

        ui->statusbar->showMessage("Stopping " + name, 5000);

        //Delete tab
        shellWindows[type] = nullptr;
        RemoveTab(type);

        UpdateNodeList();

        return true;
    }
}


void RosaWindow::QuestionRvizClose(QPushButton *buttonClicked)
{
    if(manager.GetLauncher(LauncherManager::RVIZZ2)->GetActive()){
        int disclaimer = QMessageBox::question(this, tr("ROSA Question"), tr("This button opens a custom Rviz2\nDo you want to close the openned one?"),
                                              QMessageBox::Yes | QMessageBox::No);
        if(disclaimer == QMessageBox::Yes){
            manager.StopLauncher(LauncherManager::RVIZZ2);
            buttonClicked->setChecked(false);
            ui->RvizzButton->setText("Run Rviz2");

            ui->statusbar->showMessage("Closing Rviz", 5000);

            //Delete tab
            shellWindows[LauncherManager::RVIZZ2] = nullptr;
            RemoveTab(LauncherManager::RVIZZ2);
        }
    }
}

bool RosaWindow::FirstLaunchFirmware(QPushButton* buttonClicked)
{
    if(!manager.GetLauncher(LauncherManager::FIRMWARE)->GetActive() ||
       !manager.GetLauncher(LauncherManager::LIDAR)->GetActive()    ||
       !manager.GetLauncher(LauncherManager::URDF)->GetActive())
    {
        int disclaimer = QMessageBox::question(this, tr("ROSA Question"), tr("First you need to start Odom from Firmware, URDF and LiDAR\nLaunch ROSA?"));
        if(disclaimer == QMessageBox::No)
        {
            buttonClicked->setChecked(false);
            ui->statusbar->showMessage("Launch aborted", 5000);
            return false;
        }
        else
        {
            if(!manager.GetLauncher(LauncherManager::FIRMWARE)->GetActive())
            {
                on_firmwareButton_clicked();
            }
            if(!manager.GetLauncher(LauncherManager::URDF)->GetActive())
            {
                on_URDFButton_clicked();
            }
            if(!manager.GetLauncher(LauncherManager::LIDAR)->GetActive())
            {
                on_lidarButton_clicked();
            }
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

void RosaWindow::UpdateNodeList()
{
    if(manager.GetLauncher(LauncherManager::NODE_LIST)->GetActive())
    {
        on_nodeListButton_clicked();
    }
}
