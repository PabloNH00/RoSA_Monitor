#ifndef SHELLOUTPUTWINDOW_H
#define SHELLOUTPUTWINDOW_H

#include <QWidget>
#include <QProcess>

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

    QProcess* process;
};

#endif // SHELLOUTPUTWINDOW_H
