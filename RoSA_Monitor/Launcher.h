#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QProcess>
#include<QDebug>

/*************************************************
 *          INTERFACE FOR  A SINGLE LAUNCHER     *
 * **********************************************/

class Launcher{
private:
    QProcess* launcherProcess;
    qint64 parentPID;
    QString command;
    bool active;

public:
    Launcher();
    ~Launcher();

    QProcess* GetLauncherProcess();
    qint64 GetParentPID();
    QString GetCommand();
    bool GetActive();

    void setParentPID(qint64 pid);

    void LoadParameters(QProcess* process, QString cmd);
    void SetActive(bool state);
    void resetLauncher();
};


#endif // LAUNCHER_H
