#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>

#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>

#include "launchermanager.h"
#include "shelloutputwindow.h"

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool running;

    explicit SimulationWindow(QWidget *parent = nullptr);
    ~SimulationWindow();

    /*******************
    *EXTERNAL FUNCTIONS*
    *******************/
    void SetWorkspace(QString w_path);
    QDir* getWorkspace();

private slots:
    /*******************
    *SLOT FUNCTIONS*
    *******************/
    void on_GazeboButton_clicked();

    void on_SlamButton_clicked();

    void on_RvizzButton_clicked();

    void on_graphButton_clicked();

    void on_rqtButton_clicked();

    void on_mainMenuButton_clicked();

    void on_navigationButton_clicked();

    void on_selectMapButton_clicked();

    void on_viewFramesButton_clicked();

    void on_TeleopButton_clicked();

    void on_nodeListButton_clicked();

signals:
    //Emitted when window closes
    void windowClosed();

    //Emitted to update workspace in main menu
    void showMainWindow();

protected:
    /*******************
    *EXTERNAL FUNCTIONS*
    *******************/
    void closeEvent(QCloseEvent *event) override;

    /*******************
    *INTERNAL FUNCTIONS*
    *******************/
    //Refactored process of pressing a button
    bool ButtonPressed(QPushButton* button, LauncherManager::LauncherType type, QString name);

    //Ask for launch Gazebo if another launcher is selected before and launches it
    bool FirstLaunchGazebo(QPushButton* buttonClicked);

    //Ask if close Rviz bc launcher already open a predefined Rviz
    void QuestionRvizClose(QPushButton* buttonClicked);

    //Set buttons state to off when window is closed
    void shutDownWindow();

    //Delete a shell tab and reorganize index
    void RemoveTab(LauncherManager::LauncherType type);

    // Each time a launcher is executed or closed
    void UpdateNodeList();

private:
    Ui::SimulationWindow *ui;

    LauncherManager manager;

    int numOfTabs;

    //Index assigned for each active tab; 0 if not active
    int tab_Index[LauncherManager::NUMBER_OF_LAUNCHERS];

    //Array of shellWindows objects for independent tabs
    ShellOutputWindow* shellWindows[LauncherManager::NUMBER_OF_LAUNCHERS];


};

#endif // SIMULATIONWINDOW_H
