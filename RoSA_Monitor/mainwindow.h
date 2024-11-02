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
#include "demowindow.h"


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
        DEMO_WINDOW,
        NUMBER_OF_WINDOWS
    } WindowType ;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void resizeImages();

    void resizeEvent(QResizeEvent *event) override;

    void on_EnterSimButton_clicked();

    //Called when simulation window is closed
    void onSimulationWindowClosed();

    void on_RosaButton_clicked();

    //Called when ROSA window is closed
    void onRosaWindowClosed();

    void on_DemoButton_clicked();

    //Called when Demo window is closed
    void onDemoWindowClosed();

    void on_select_workspace_button_clicked();

    void on_previousMenuButton_clicked();

    // Method connected to a signal from other menus to update workspace dir in main menu
    void onGetWorkspaceFromWindow();


protected:
    //Called when monitor is requested to close
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    WindowType activeWindow;
    SimulationWindow* simWindow;
    RosaWindow* rosaWindow;
    DemoWindow* demoWindow;
    QDir* workspace;

    QPixmap UPM_logo;
    QPixmap ETSIDI_logo;

};
#endif // MAINWINDOW_H
