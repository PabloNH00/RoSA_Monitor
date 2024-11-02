#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), workspace(nullptr)
    , UPM_logo(":/resources/img/UPM_logo_text.png")
    , ETSIDI_logo(":/resources/img/ETSIDI_logo.png")
{
    ui->setupUi(this);

    // Set images init config
    resizeImages();

    //Set the actial window to MAIN_WINDOW
    activeWindow = MAIN_WINDOW;
    ui->statusbar->showMessage("Select any menu");

    //Prepare simulation window
    simWindow = new SimulationWindow(this);
    rosaWindow = new RosaWindow(this);
    demoWindow = new DemoWindow(this);

}

MainWindow::~MainWindow()
{
    if(simWindow != nullptr)
    {
         delete simWindow;
    }
    if(rosaWindow != nullptr)
    {
         delete rosaWindow;
    }
    if(demoWindow != nullptr)
    {
         delete demoWindow;
    }
    delete workspace;
    delete ui;
}

// Override resizeEvent to resize images
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);  // Call base event to mantain normal functionality
    resizeImages();
}


void MainWindow::resizeImages() {
    ui->imgUPM->setPixmap(UPM_logo.scaled(ui->imgUPM->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->imgETSIDI->setPixmap(ETSIDI_logo.scaled(ui->imgETSIDI->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MainWindow::on_EnterSimButton_clicked()
{
    //State machine for simulation mode button pressed
    switch(activeWindow)
    {
    case MAIN_WINDOW:
        //Run simulation window
        activeWindow = SIMULATION_WINDOW;

        connect(simWindow, &SimulationWindow::windowClosed, this, &MainWindow::onSimulationWindowClosed); //Connect windowClosed signal to the method
        QObject::connect(simWindow, &SimulationWindow::showMainWindow, this, &MainWindow::onGetWorkspaceFromWindow); // Connect signal to update workspace dir

        ui->statusbar->showMessage("Simulation Menu active");

        //Set the workspace
        if(workspace != nullptr)
        {
            simWindow->SetWorkspace(workspace->path());
        }

        simWindow->showMaximized();
        ui->EnterSimButton->setText("Exit simulation Menu");

        break;

    case SIMULATION_WINDOW:
        //Close simulation window due to second click on button
        simWindow->close();

        //if no processes running or user choose to close them
        if(!simWindow->running)
        {
            //Prepare another simulation window
            delete simWindow;
            simWindow = new SimulationWindow(this);

            ui->EnterSimButton->setChecked(false);

            ui->EnterSimButton->setText("Enter simulation Menu");
            activeWindow = MAIN_WINDOW;

            ui->statusbar->showMessage("Select any menu");
        }
        else
        {
           if(activeWindow == SIMULATION_WINDOW)
           {
                ui->EnterSimButton->setChecked(true);
           }

        }

        break;
    case DEMO_WINDOW:
    case ROSA_WINDOW:
        //Show alert suggesting to close ROSA menu first
        QMessageBox::information(this, tr("ROSA Info"), tr("You can't enter simulation Menu while other menu is active\nClose other menu first"));
        ui->EnterSimButton->setChecked(false);

        break;

    default:
        break;
    }
}

void MainWindow::onSimulationWindowClosed()
{
    //Once simulation window is closed set checked to false and update actual window and workspace
    ui->EnterSimButton->setChecked(false);
    ui->EnterSimButton->setText("Enter simulation Menu");
    ui->statusbar->showMessage("Select any menu");
    activeWindow = MAIN_WINDOW;

    //Save workspace if selected on simulation window
    if(workspace == nullptr && simWindow->getWorkspace() != nullptr)
    {
        workspace = new QDir;
        *workspace = *simWindow->getWorkspace();
        ui->workspace_selected->setText(workspace->dirName());
    }
    //Prepare another simulation window
    delete simWindow;
    simWindow = new SimulationWindow(this);
}


void MainWindow::on_RosaButton_clicked()
{
    //State machine for ROSA mode button pressed
    switch(activeWindow)
    {
    case MAIN_WINDOW:
        //Run simulation window
        activeWindow = ROSA_WINDOW;

        connect(rosaWindow, &RosaWindow::windowClosed, this, &MainWindow::onRosaWindowClosed); //Connect windowClosed signal to the method
        QObject::connect(rosaWindow, &RosaWindow::showMainWindow, this, &MainWindow::onGetWorkspaceFromWindow); // Connect signal to update workspace dir

        ui->statusbar->showMessage("ROSA Menu active");

        //Set the workspace
        if(workspace != nullptr)
        {
            rosaWindow->SetWorkspace(workspace->path());
        }

        rosaWindow->showMaximized();
        ui->RosaButton->setText("Exit ROSA Menu");

        break;
    case DEMO_WINDOW:
    case SIMULATION_WINDOW:
        QMessageBox::information(this, tr("ROSA Info"), tr("You can't enter ROSA Menu while other menu is active\nClose other menu first"));
        ui->RosaButton->setChecked(false);
        break;
    case ROSA_WINDOW:
        //Close simulation window due to second click on button
        rosaWindow->close();

        //if no processes running or user choose to close them
        if(!rosaWindow->running)
        {
            //Prepare another simulation window
            delete rosaWindow;
            rosaWindow = new RosaWindow(this);

            ui->RosaButton->setChecked(false);

            ui->RosaButton->setText("Enter ROSA Menu");
            activeWindow = MAIN_WINDOW;

            ui->statusbar->showMessage("Select any menu");
        }
        else
        {
           if(activeWindow == ROSA_WINDOW)
           {
                ui->RosaButton->setChecked(true);
           }

        }
        break;
    default:
        break;
    }
}

void MainWindow::onRosaWindowClosed()
{
    //Once simulation window is closed set checked to false and update actual window and workspace
    ui->RosaButton->setChecked(false);
    ui->RosaButton->setText("Enter ROSA Menu");
    ui->statusbar->showMessage("Select any menu");
    activeWindow = MAIN_WINDOW;

    //Save workspace if selected on ROSA window
    if(workspace == nullptr && rosaWindow->getWorkspace() != nullptr)
    {
        workspace = new QDir;
        *workspace = *rosaWindow->getWorkspace();
        ui->workspace_selected->setText(workspace->dirName());
    }
    delete rosaWindow;
    rosaWindow = new RosaWindow(this);
}

void MainWindow::on_DemoButton_clicked()
{
    //State machine for ROSA mode button pressed
    switch(activeWindow)
    {
    case MAIN_WINDOW:
        //Run simulation window
        activeWindow = DEMO_WINDOW;

        connect(demoWindow, &DemoWindow::windowClosed, this, &MainWindow::onDemoWindowClosed); //Connect windowClosed signal to the method
        QObject::connect(demoWindow, &DemoWindow::showMainWindow, this, &MainWindow::onGetWorkspaceFromWindow); // Connect signal to update workspace dir

        ui->statusbar->showMessage("Demo Speak active");

        //Set the workspace
        if(workspace != nullptr)
        {
            demoWindow->SetWorkspace(workspace->path());
        }

        demoWindow->showMaximized();
        ui->DemoButton->setText("Exit Demo Speak");

        break;
    case ROSA_WINDOW:
    case SIMULATION_WINDOW:
        QMessageBox::information(this, tr("ROSA Info"), tr("You can't enter ROSA Menu while other menu is active\nClose other menu first"));
        ui->DemoButton->setChecked(false);
        break;
    case DEMO_WINDOW:
        //Close simulation window due to second click on button
        demoWindow->close();

        //if no processes running or user choose to close them
        if(!demoWindow->running)
        {
            //Prepare another simulation window
            delete demoWindow;
            demoWindow = new DemoWindow(this);

            ui->DemoButton->setChecked(false);

            ui->DemoButton->setText("Enter Demo Speak");
            activeWindow = MAIN_WINDOW;

            ui->statusbar->showMessage("Select any menu");
        }
        else
        {
           if(activeWindow == DEMO_WINDOW)
           {
                ui->DemoButton->setChecked(true);
           }

        }
        break;
    default:
        break;
    }
}

void MainWindow::onDemoWindowClosed()
{
    //Once simulation window is closed set checked to false and update actual window and workspace
    ui->DemoButton->setChecked(false);
    ui->DemoButton->setText("Enter Demo Speak");
    ui->statusbar->showMessage("Select any menu");
    activeWindow = MAIN_WINDOW;

    //Save workspace if selected on DEMO window
    if(workspace == nullptr && demoWindow->getWorkspace() != nullptr)
    {
        workspace = new QDir;
        *workspace = *demoWindow->getWorkspace();
        ui->workspace_selected->setText(workspace->dirName());
    }
    delete demoWindow;
    demoWindow = new DemoWindow(this);
}

void MainWindow::on_select_workspace_button_clicked()
{
    //Open file explorer to select workspace
    QString workspace_name = QFileDialog::getExistingDirectory(this, "Select your workspace", QDir::homePath(), QFileDialog::ShowDirsOnly);
    if(workspace_name == "")
    {
        ui->statusbar->showMessage("No workspace selected", 5000);

        return;
    }

    workspace = new QDir(workspace_name);
    qDebug()<<workspace->path();
    ui->workspace_selected->setText(workspace->dirName());


    //Verify if /maps exists
    QString mapsDirPath = workspace->filePath("maps");
    bool mapsExist = workspace->exists("maps");

    //If not, create /maps in workspace
    if (!mapsExist)
    {
        workspace->mkpath(mapsDirPath);
    }


    //Update workspace in the active window
    switch(activeWindow)
    {
    case SIMULATION_WINDOW:

        if(workspace != nullptr)
        {
            simWindow->SetWorkspace(workspace->path());
        }

        break;
    case ROSA_WINDOW:

        if(workspace != nullptr)
        {
            rosaWindow->SetWorkspace(workspace->path());
        }

        break;
    case DEMO_WINDOW:

        if(workspace != nullptr)
        {
            demoWindow->SetWorkspace(workspace->path());
        }

        break;
    case MAIN_WINDOW:
    default:
        break;
    }

}


void MainWindow::on_previousMenuButton_clicked()
{
    //Go to active menu
    switch(activeWindow)
    {
    case MAIN_WINDOW:
        QMessageBox::information(this, tr("ROSA Info"), tr("Any menu selected"));
        break;
    case SIMULATION_WINDOW:
        if(simWindow->isHidden())
        {
            simWindow->show();
        }
        else
        {
            simWindow->raise();
        }

        break;
    case ROSA_WINDOW:
        if(rosaWindow->isHidden())
        {
            rosaWindow->show();
        }
        else
        {
            rosaWindow->raise();
        }

        break;
    case DEMO_WINDOW:
        if(demoWindow->isHidden())
        {
            demoWindow->show();
        }
        else
        {
            demoWindow->raise();
        }

        break;
    default:
        break;
    }
}



void MainWindow::closeEvent(QCloseEvent *event)
{
    //Do not let close the main window if any other window is active
    if(activeWindow == SIMULATION_WINDOW || activeWindow == ROSA_WINDOW || activeWindow == DEMO_WINDOW)
    {
        QMessageBox::critical(this, tr("WARNING"), tr("You can't close the application while process are running\nClose other windows first"));
        event->ignore();  //Ignore close event
    }
    else
    {
        event->accept();  //Close window
    }
}

void MainWindow::onGetWorkspaceFromWindow()
{
    //Update workspace dir from other menu
    switch(activeWindow)
    {
    case MAIN_WINDOW:
        QMessageBox::information(this, tr("ROSA Info"), tr("Any menu selected"));
        break;
    case SIMULATION_WINDOW:

        //Save workspace if selected on simulation window
        if(workspace == nullptr && simWindow->getWorkspace() != nullptr)
        {
            workspace = new QDir;
            *workspace = *simWindow->getWorkspace();
            ui->workspace_selected->setText(workspace->dirName());
        }

        break;
    case ROSA_WINDOW:
        //Save workspace if selected on ROSA window
        if(workspace == nullptr && rosaWindow->getWorkspace() != nullptr)
        {
            workspace = new QDir;
            *workspace = *rosaWindow->getWorkspace();
            ui->workspace_selected->setText(workspace->dirName());
        }

        break;
    case DEMO_WINDOW:
        //Save workspace if selected on DEMO window
        if(workspace == nullptr && demoWindow->getWorkspace() != nullptr)
        {
            workspace = new QDir;
            *workspace = *demoWindow->getWorkspace();
            ui->workspace_selected->setText(workspace->dirName());
        }

        break;
    default:
        break;
    }
}


