#ifndef DEMOWINDOW_H
#define DEMOWINDOW_H

#include <QMainWindow>

#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>

#include "launchermanager.h"
#include "shelloutputwindow.h"

namespace Ui {
class DemoWindow;
}

class DemoWindow : public QMainWindow
{
    Q_OBJECT

public:
    bool running;

    explicit DemoWindow(QWidget *parent = nullptr);
    ~DemoWindow();

    /*******************
    *EXTERNAL FUNCTIONS*
    *******************/
    void SetWorkspace(QString w_path);
    QDir* getWorkspace();

private slots:
    /*******************
    *SLOT FUNCTIONS*
    *******************/
    void on_graphButton_clicked();

    void on_mainMenuButton_clicked();

    void on_nodeListButton_clicked();

    void on_DemoButton_clicked();

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

    //Set buttons state to off when window is closed
    void shutDownWindow();

    //Delete a shell tab and reorganize index
    void RemoveTab(LauncherManager::LauncherType type);

    // Each time a launcher is executed or closed
    void UpdateNodeList();

private:
    Ui::DemoWindow *ui;

    LauncherManager manager;

    int numOfTabs;

    //Index assigned for each active tab; 0 if not active
    int tab_Index[LauncherManager::NUMBER_OF_LAUNCHERS];

    //Array of shellWindows objects for independent tabs
    ShellOutputWindow* shellWindows[LauncherManager::NUMBER_OF_LAUNCHERS];
};

#endif // DEMOWINDOW_H
