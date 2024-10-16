#include "Launcher.h"

Launcher::Launcher():active(false)
{
    launcherProcess = nullptr;
}

Launcher::~Launcher()
{
    if(launcherProcess != nullptr)
    {
        delete launcherProcess;
    }
    active = false;
    command = "0";
    parentPID = 0;
}

QProcess* Launcher::GetLauncherProcess()
{
    return launcherProcess;
}
qint64 Launcher::GetParentPID()
{
    return parentPID;
}
QString Launcher::GetCommand()
{
    return command;
}
bool Launcher::GetActive()
{
    return active;
}

void Launcher::setParentPID(qint64 pid)
{
    parentPID = pid;
}

void Launcher::SetActive(bool state)
{
    active = state;
}

void Launcher::LoadParameters(QProcess* process, QString cmd)
{
    launcherProcess = process;
    command = cmd;
}

void Launcher::resetLauncher()
{
    launcherProcess = nullptr;
    parentPID = 0;
    command = "";
}
