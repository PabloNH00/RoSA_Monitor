#ifndef ROSAWINDOW_H
#define ROSAWINDOW_H

#include <QMainWindow>

#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>

#include "launchermanager.h"

namespace Ui {
class RosaWindow;
}

class RosaWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool running;

    explicit RosaWindow(QWidget *parent = nullptr);
    ~RosaWindow();

    /*******************
    *EXTERNAL FUNCTIONS*
    *******************/
    void SetWorkspace(QString w_path);
    QDir* getWorkspace();

private slots:
    void on_firmwareButton_clicked();

    void on_mainMenuButton_clicked();

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
    Ui::RosaWindow *ui;

   LauncherManager manager;
};

#endif // ROSAWINDOW_H
