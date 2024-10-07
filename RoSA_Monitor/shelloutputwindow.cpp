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

void ShellOutputWindow::setLauncherProcess(QProcess *process)
{
    if(process != nullptr)
    {
        launcherProcess = process;
    }
}

void ShellOutputWindow::ClearText()
{
    ui->shellTextOutput->clear();
}

void ShellOutputWindow::readProcessOutput()
{
    if(launcherProcess != nullptr)
    {
        //Read console output and print it on QPlainText
        ui->shellTextOutput->appendPlainText(launcherProcess->readAllStandardOutput());
    }
}
