#ifndef LAUNCHERMANAGER_H
#define LAUNCHERMANAGER_H

#include <QProcess>
#include <QDir>

#include "Launcher.h"


/*************************************************
 *  MANAGEMENT OF BASIC LAUNCHER FUNCIONALITIES  *
 * **********************************************/
class LauncherManager{
public:

    //List of all launchers in monitor
    typedef enum{
        RVIZZ2,
        RQT,
        RQT_GRAPH,
        VIEW_FRAMES,
        TELEOP,
        GAZEBO_SIM,
        SLAM_SIM,
        NAVIGATION,
        NUMBER_OF_LAUNCHERS
    } LauncherType ;

private:
    //Array to store all launchers
    Launcher* List_of_Launcher[NUMBER_OF_LAUNCHERS];
    QDir* workspace_dir;
    QFile* mapLoaded;

public:
    LauncherManager();
    ~LauncherManager();

    //Method to send SIGTERM to all process derivated from a launcher
    void StopLauncher(LauncherType type);

    /*Method to call load Launcher::LoadParameters(QProcess* process, QString cmd)
    *with corresponding values                                                  */
    bool CreateLauncher(LauncherType type, QProcess* process);

    //Method to launch the process and set launcher active
    bool Launch(LauncherType type);

    //Method to check if any launcher of List_of_Launcher is active
    bool IsAnyActive();

    //Method to stop all active launchers
    void ShutdownLaunchers();

    Launcher* GetLauncher(LauncherType type );

    //Create a QDir* with the path selected from file explorer
    void SetWorkspaceDir(QString w_Path);

    QDir* GetWorkspacePath();

    //Create a QFile* with the path selected from file explorer
    void SetMap(QString w_Path);

    QFile* GetMap();

    void setActive(bool state, LauncherType type);
};


#endif // LAUNCHERMANAGER_H
