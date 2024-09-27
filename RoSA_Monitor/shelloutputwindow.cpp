#include "shelloutputwindow.h"
#include "ui_shelloutputwindow.h"

ShellOutputWindow::ShellOutputWindow(QWidget *parent, QProcess* process) :
    QWidget(parent),
    ui(new Ui::ShellOutputWindow), launcherProcess(process)
{
    ui->setupUi(this);
}

ShellOutputWindow::~ShellOutputWindow()
{
    delete ui;
}


void ShellOutputWindow::readProcessOutput()
{
    if(launcherProcess != nullptr)
    {
        //Read console output and print it on QPlainText
        ui->shellTextOutput->appendPlainText(launcherProcess->readAllStandardOutput());
    }
}
