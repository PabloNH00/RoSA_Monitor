#include "rosawindow.h"
#include "ui_rosawindow.h"

RosaWindow::RosaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RosaWindow)
{
    ui->setupUi(this);
}

RosaWindow::~RosaWindow()
{

    if (manager.GetLauncher(LauncherManager::FIRMWARE)->GetActive()) {
        manager.StopLauncher(LauncherManager::FIRMWARE);
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



void RosaWindow::on_mainMenuButton_clicked()
{
    //Hide the window to show main menu
    this->hide();
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

/*
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

bool RosaWindow::FirstLaunchGazebo(QPushButton* buttonClicked)
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
*/
void RosaWindow::shutDownWindow()
{

    ui->firmwareButton->setChecked(false);
    ui->firmwareButton->setText("Run Firmware");
/*
    ui->rqtButton->setChecked(false);
    ui->rqtButton->setText("Run rqt");

    ui->graphButton->setChecked(false);
    ui->graphButton->setText("Run rqt_graph");

    ui->TeleopButton->setChecked(false);
    ui->TeleopButton->setText("Run teleop_twist");
    */

}

