#include "simulationwindow.h"
#include "ui_simulationwindow.h"


SimulationWindow::SimulationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulationWindow), numOfTabs(1)
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

SimulationWindow::~SimulationWindow()
{
    for(int i = 0; i < LauncherManager::NUMBER_OF_LAUNCHERS; i++)
    {
        if(shellWindows[i] != nullptr)
            delete shellWindows[i];
    }
    delete ui;
}

/****************************************************
*               EXTERNAL FUNCTIONS                  *
****************************************************/
void SimulationWindow::closeEvent(QCloseEvent *event)
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


void SimulationWindow::SetWorkspace(QString w_path)
{
    manager.SetWorkspaceDir(w_path);
}

QDir* SimulationWindow::getWorkspace()
{
    return manager.GetWorkspacePath();
}


/****************************************************
*               SLOT FUNCTIONS                      *
****************************************************/

void SimulationWindow::on_GazeboButton_clicked()
{
    if(ButtonPressed(ui->GazeboButton, LauncherManager::GAZEBO_SIM, "Gazebo"))
    {
        qDebug()<<"Button Gazebo correctly executed";
    }
    else
    {
        qDebug()<<"Error executing Gazebo  ";
        ui->GazeboButton->setChecked(false);

    }
}


void SimulationWindow::on_SlamButton_clicked()
{
    //Check if navigation is active
    if(manager.GetLauncher(LauncherManager::NAVIGATION_SIM)->GetActive())
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("Can not open SLAM while navigating"));
        ui->SlamButton->setChecked(false);

        ui->statusbar->showMessage("Close navigation before launch SLAM", 5000);

        return;
    }
    if(!manager.GetLauncher(LauncherManager::SLAM_SIM)->GetActive())
    {
        QuestionRvizClose(ui->RvizzButton);
        if(!FirstLaunchGazebo(ui->SlamButton))
        {
            return;
        }
        else
        {
            //If this process is executing do not duplicate
            if (manager.GetLauncher(LauncherManager::SLAM_SIM)->GetLauncherProcess() != nullptr)
            {
                ui->statusbar->showMessage("Process SLAM already executing", 5000);
                return;
            }
            //Create new process
            if(!manager.CreateLauncher(LauncherManager::SLAM_SIM, new QProcess(this)))
            {
                ui->statusbar->showMessage("Launch failed", 5000);
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

                ui->statusbar->showMessage("Launching SLAM", 5000);

                //Add new tab
                ui->tabsimulationWidget->addTab(shellWindows[LauncherManager::SLAM_SIM], "SLAM shell");
                tab_Index[LauncherManager::SLAM_SIM] = numOfTabs++;

                UpdateNodeList();
            }
        }

    }
    //Stop the process due to a second press on button
    else
    {
        ui->SlamButton->setText("Run SLAM");
        manager.StopLauncher(LauncherManager::SLAM_SIM);
        ui->SlamButton->setChecked(false);

        ui->statusbar->showMessage("Stopping SLAM", 5000);

        //Delete tab
        shellWindows[LauncherManager::SLAM_SIM] = nullptr;
        RemoveTab(LauncherManager::SLAM_SIM);

        UpdateNodeList();
    }
}

void SimulationWindow::on_RvizzButton_clicked()
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


void SimulationWindow::on_graphButton_clicked()
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


void SimulationWindow::on_rqtButton_clicked()
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

void SimulationWindow::on_mainMenuButton_clicked()
{
    // Emit signal to main window to update workspace
    emit showMainWindow();

    //Hide the window to show main menu
    this->hide();
}


void SimulationWindow::on_navigationButton_clicked()
{
    //Check if SLAM is active
    if(manager.GetLauncher(LauncherManager::SLAM_SIM)->GetActive())
    {
        QMessageBox::information(this, tr("ROSA Info"), tr("Can not open navigation while mapping"));
        ui->navigationButton->setChecked(false);

        ui->statusbar->showMessage("Close SLAM before launch navigation", 5000);

        return;
    }
    if(!manager.GetLauncher(LauncherManager::NAVIGATION_SIM)->GetActive())
    {
        QuestionRvizClose(ui->RvizzButton);
        if(!FirstLaunchGazebo(ui->navigationButton))
        {
            return;
        }
        else
        {
            //If this process is executing do not duplicate
            if (manager.GetLauncher(LauncherManager::NAVIGATION_SIM)->GetLauncherProcess() != nullptr)
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
            //Create new process
            if(!manager.CreateLauncher(LauncherManager::NAVIGATION_SIM, new QProcess(this)))
            {
                ui->statusbar->showMessage("Launch failed", 5000);
                return;
            }
            else
            {
                //Create shell window and connect shell output of process launcher to the read output slot
                shellWindows[LauncherManager::NAVIGATION_SIM] = new ShellOutputWindow(this, manager.GetLauncher(LauncherManager::NAVIGATION_SIM)->GetLauncherProcess());
                connect(manager.GetLauncher(LauncherManager::NAVIGATION_SIM)->GetLauncherProcess(), &QProcess::readyReadStandardOutput, shellWindows[LauncherManager::NAVIGATION_SIM], &ShellOutputWindow::readProcessOutput);

                //Launch process
                manager.Launch(LauncherManager::NAVIGATION_SIM);
                ui->navigationButton->setChecked(true);
                ui->navigationButton->setText("Stop Navigation");

                ui->statusbar->showMessage("Launching Navigation", 5000);

                //Add new tab
                ui->tabsimulationWidget->addTab(shellWindows[LauncherManager::NAVIGATION_SIM], "Navigation shell");
                tab_Index[LauncherManager::NAVIGATION_SIM] = numOfTabs++;

                UpdateNodeList();
            }
        }

    }
    //Stop process
    else
    {
        ui->navigationButton->setText("Run Navigation");
        manager.StopLauncher(LauncherManager::NAVIGATION_SIM);
        ui->navigationButton->setChecked(false);

        ui->statusbar->showMessage("Stopping Navigation", 5000);

        //Delete tab
        shellWindows[LauncherManager::NAVIGATION_SIM] = nullptr;
        RemoveTab(LauncherManager::NAVIGATION_SIM);

        UpdateNodeList();
    }
}


void SimulationWindow::on_selectMapButton_clicked()
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


void SimulationWindow::on_viewFramesButton_clicked()
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


void SimulationWindow::on_TeleopButton_clicked()
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

void SimulationWindow::on_nodeListButton_clicked()
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
            ui->tabsimulationWidget->addTab(shellWindows[LauncherManager::NODE_LIST], "ROS2 node list");
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

bool SimulationWindow::ButtonPressed(QPushButton* button, LauncherManager::LauncherType type, QString name)
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
            ui->statusbar->showMessage("Maps folder created", 5000);
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

            //Add new tab
            ui->tabsimulationWidget->addTab(shellWindows[type], name + " shell");
            tab_Index[type] = numOfTabs++;

            ui->statusbar->showMessage("Launching " + name, 5000);

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

void SimulationWindow::QuestionRvizClose(QPushButton *buttonClicked)
{
    if(manager.GetLauncher(LauncherManager::RVIZZ2)->GetActive()){
        int disclaimer = QMessageBox::question(this, tr("ROSA Question"), tr("This button opens a custom Rviz2\nDo you want to close the openned one?"),
                                              QMessageBox::Yes | QMessageBox::No);
        if(disclaimer == QMessageBox::Yes)
        {
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

bool SimulationWindow::FirstLaunchGazebo(QPushButton* buttonClicked)
{
    if(!manager.GetLauncher(LauncherManager::GAZEBO_SIM)->GetActive())
    {
        int disclaimer = QMessageBox::question(this, tr("ROSA Question"), tr("First you need to start gazebo\nLaunch Gazebo?"));
        if(disclaimer == QMessageBox::No)
        {
            ui->statusbar->showMessage("Launch aborted", 5000);
            buttonClicked->setChecked(false);
            return false;
        }
        else
        {
            on_GazeboButton_clicked();
        }
    }
    return true;
}

void SimulationWindow::RemoveTab(LauncherManager::LauncherType type)
{
    //Delete tab
    ui->tabsimulationWidget->removeTab(tab_Index[type]);
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

void SimulationWindow::UpdateNodeList()
{
    //Update node list
    if(manager.GetLauncher(LauncherManager::NODE_LIST)->GetActive())
    {
        on_nodeListButton_clicked();
    }
}
