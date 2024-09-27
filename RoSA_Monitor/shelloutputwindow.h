#ifndef SHELLOUTPUTWINDOW_H
#define SHELLOUTPUTWINDOW_H

#include <QWidget>
#include <QProcess>

/*************************************************
 *WINDOW TO BE SHOWED WITH LAUNCHER'S SHELL INFO *
 * **********************************************/

namespace Ui {
class ShellOutputWindow;
}

class ShellOutputWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShellOutputWindow(QWidget *parent = nullptr, QProcess* process = nullptr);
    ~ShellOutputWindow();

public slots:
    //Slot for reading std output of process
    void readProcessOutput();

private:
    Ui::ShellOutputWindow *ui;

    //Process whose output is read
    QProcess* launcherProcess;
};

#endif // SHELLOUTPUTWINDOW_H
