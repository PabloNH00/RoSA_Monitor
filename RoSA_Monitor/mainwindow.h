#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QFileDialog>


#include "simulationwindow.h"
#include "rosawindow.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Types of windows
    typedef enum{
        MAIN_WINDOW,
        SIMULATION_WINDOW,
        ROSA_WINDOW,
        NUMBER_OF_WINDOWS
    } WindowType ;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_EnterSimButton_clicked();

    //Called when simulation window is closed
    void onSimulationWindowClosed();

    //Called when ROSA window is closed
    void onRosaWindowClosed();

    void on_RosaButton_clicked();

    void on_select_workspace_button_clicked();

    void on_previousMenuButton_clicked();

protected:
    //Called when monitor is requested to close
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    WindowType activeWindow;
    SimulationWindow* simWindow;
    RosaWindow* rosaWindow;
    QDir* workspace;

};
#endif // MAINWINDOW_H
