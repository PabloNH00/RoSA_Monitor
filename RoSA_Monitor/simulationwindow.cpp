#include "simulationwindow.h"
#include "ui_simulationwindow.h"


SimulationWindow::SimulationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);
}

SimulationWindow::~SimulationWindow()
{
    if (manager.GetLauncher(LauncherManager::SLAM_SIM)->GetActive()) {
        manager.StopLauncher(LauncherManager::SLAM_SIM);
    }
    if (manager.GetLauncher(LauncherManager::GAZEBO_SIM)->GetActive()) {
        manager.StopLauncher(LauncherManager::GAZEBO_SIM);
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
        int disclaimer = QMessageBox::warning(this, tr("RoSA Shutdown"), tr("Are you sure you want to close?\nIt will shutdown all active processes"),
                                              QMessageBox::Yes | QMessageBox::No);

        //stop all processes
        if (disclaimer == QMessageBox::Yes)
        {
            running = false;
            shutDownWindow();
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
                //Run the process
                manager.Launch(LauncherManager::SLAM_SIM);
                ui->SlamButton->setChecked(true);
            }
            ui->SlamButton->setText("Stop SLAM");
        }

    }
    //Stop the process due to a second press on button
    else
    {
        ui->SlamButton->setText("Run SLAM");
        manager.StopLauncher(LauncherManager::SLAM_SIM);
        ui->SlamButton->setChecked(false);
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
    //Hide the window to show main menu
    this->hide();
}


void SimulationWindow::on_navigationButton_clicked()
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
        if(!FirstLaunchGazebo(ui->navigationButton))
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
                //Launch process
                manager.Launch(LauncherManager::NAVIGATION);
                ui->navigationButton->setChecked(true);
            }
            ui->navigationButton->setText("Stop Navigation");
        }

    }
    //Stop process
    else
    {
        ui->navigationButton->setText("Run Navigation");
        manager.StopLauncher(LauncherManager::NAVIGATION);
        ui->navigationButton->setChecked(false);
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
        return;
    }
    else
    {
        manager.SetMap(map_name);
        QFileInfo mapInfo(*manager.GetMap());
        ui->mapLabel->setText(mapInfo.fileName());
    }
}


void SimulationWindow::on_viewFramesButton_clicked()
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



/****************************************************
*               INTERNAL FUNCTIONS                  *
****************************************************/

bool SimulationWindow::ButtonPressed(QPushButton* button, LauncherManager::LauncherType type, QString name)
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
            //Launch process
            manager.Launch(type);
            button->setChecked(true);
            button->setText("Stop " + name);
            return true;
        }
    }
    else
    {
        button->setText("Run " + name);
        manager.StopLauncher(type);
        button->setChecked(false);
        return true;
    }
}

void SimulationWindow::QuestionRvizClose(QPushButton *buttonClicked)
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

bool SimulationWindow::FirstLaunchGazebo(QPushButton* buttonClicked)
{
    if(!manager.GetLauncher(LauncherManager::GAZEBO_SIM)->GetActive())
    {
        int disclaimer = QMessageBox::question(this, tr("RoSA Question"), tr("First you need to start gazebo\nLaunch Gazebo?"));
        if(disclaimer == QMessageBox::No)
        {
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

void SimulationWindow::shutDownWindow()
{
    ui->GazeboButton->setChecked(false);
    ui->GazeboButton->setText("Run Gazebo");

    ui->SlamButton->setChecked(false);
    ui->SlamButton->setText("Run SLAM");

    ui->navigationButton->setChecked(false);
    ui->navigationButton->setText("Run Navigation");

    ui->RvizzButton->setChecked(false);
    ui->RvizzButton->setText("Run RVIZ2");

    ui->rqtButton->setChecked(false);
    ui->rqtButton->setText("Run rqt");

    ui->graphButton->setChecked(false);
    ui->graphButton->setText("Run rqt_graph");

    ui->TeleopButton->setChecked(false);
    ui->TeleopButton->setText("Run teleop_twist");

    ///////

}

