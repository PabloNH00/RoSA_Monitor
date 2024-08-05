#include "shelloutputwindow.h"
#include "ui_shelloutputwindow.h"

ShellOutputWindow::ShellOutputWindow(QWidget *parent, QProcess* process) :
    QWidget(parent),
    ui(new Ui::ShellOutputWindow), process(process)
{
    ui->setupUi(this);
}

ShellOutputWindow::~ShellOutputWindow()
{
    delete ui;
}


void ShellOutputWindow::readProcessOutput()
{
    //Read console output and print it on QPlainText
    ui->shellTextOutput->appendPlainText(process->readAllStandardOutput());
}
