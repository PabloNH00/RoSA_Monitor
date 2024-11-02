#include "demowindow.h"
#include "ui_demowindow.h"

DemoWindow::DemoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DemoWindow), numOfTabs(1)
{
    for(int i = 0; i < LauncherManager::NUMBER_OF_LAUNCHERS; i++)
    {
        tab_Index[i] = 0;
        shellWindows[i] = nullptr;
    }

    ui->setupUi(this);
}

DemoWindow::~DemoWindow()
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

void DemoWindow::closeEvent(QCloseEvent *event)
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


void DemoWindow::SetWorkspace(QString w_path)
{
    manager.SetWorkspaceDir(w_path);
}

QDir* DemoWindow::getWorkspace()
{
    return manager.GetWorkspacePath();
}


/****************************************************
*               SLOT FUNCTIONS                      *
****************************************************/

void DemoWindow::on_graphButton_clicked()
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

void DemoWindow::on_mainMenuButton_clicked()
{
    // Emit signal to main window to update workspace
    emit showMainWindow();

    //Hide the window to show main menu
    this->hide();
}

void DemoWindow::on_nodeListButton_clicked()
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
            ui->tabdemoWidget->addTab(shellWindows[LauncherManager::NODE_LIST], "ROS2 node list");
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

void DemoWindow::on_DemoButton_clicked()
{
    if(ButtonPressed(ui->DemoButton, LauncherManager::DEMO, "Demo"))
    {
        qDebug()<<"Button Demo correctly executed";
    }
    else
    {
        qDebug()<<"Error executing Demo  ";
        ui->DemoButton->setChecked(false);

    }
}

/****************************************************
*               INTERNAL FUNCTIONS                  *
****************************************************/

bool DemoWindow::ButtonPressed(QPushButton* button, LauncherManager::LauncherType type, QString name)
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
            ui->tabdemoWidget->addTab(shellWindows[type], name + " shell");
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

void DemoWindow::RemoveTab(LauncherManager::LauncherType type)
{
    //Delete tab
    ui->tabdemoWidget->removeTab(tab_Index[type]);
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

void DemoWindow::UpdateNodeList()
{
    if(manager.GetLauncher(LauncherManager::NODE_LIST)->GetActive())
    {
        on_nodeListButton_clicked();
    }
}
