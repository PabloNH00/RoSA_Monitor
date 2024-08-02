#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QMainWindow>

#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>

#include "launchermanager.h"

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

signals:
    //Emitted when window closes
    void windowClosed();

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

private:
    Ui::SimulationWindow *ui;

    LauncherManager manager;


};

#endif // SIMULATIONWINDOW_H
