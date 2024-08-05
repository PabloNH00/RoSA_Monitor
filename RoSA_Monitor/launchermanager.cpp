#include "launchermanager.h"
#include <QDebug>
//#include <QThread>

LauncherManager::LauncherManager(): workspace_dir(nullptr), mapLoaded(nullptr)
{
    for(int i=0; i<NUMBER_OF_LAUNCHERS;i++)
    {
       //Initialice launchers in the array
       List_of_Launcher[i] = new Launcher();
    }
}

LauncherManager::~LauncherManager()
{
    for(int i=0; i<NUMBER_OF_LAUNCHERS;i++)
    {
        if(List_of_Launcher[i] != nullptr)
        {
            delete List_of_Launcher[i];
        }
    }
    delete workspace_dir;
    delete mapLoaded;
}

void LauncherManager::StopLauncher(LauncherType type){
    //Process to kill active process in launcher
    QProcess* killProcess = new QProcess;
    //Bash command to kill all process in the process tree of the parent PIF
    QString str = "pstree -p " + QString::number(this->List_of_Launcher[type]->GetParentPID()) + "  | awk -F'[()]' '{for(i=2;i<=NF;i+=2) print $i}' | sort -n | uniq | xargs kill -TERM";

    if(type == RQT_GRAPH || type == RQT)
    {
        str = "pstree -p " + QString::number(this->List_of_Launcher[type]->GetParentPID()) + "  | awk -F'[()]' '{for(i=2;i<=NF;i+=2) print $i}' | sort -n | uniq | xargs kill -9";
    }

    //Execute kill process with the bash command
    qDebug()<<"Stopping process" << QString::number(this->List_of_Launcher[type]->GetParentPID());
    killProcess->start("bash", QStringList()<<"-c"<<str);
    killProcess->waitForFinished();
    //QThread::sleep(5);

    //Aditional kill process to Gazebo server processes (usually remains after first try)
    if(type == GAZEBO_SIM){
        QProcess* getGazPID = new QProcess;
        QProcess* killGazebo = new QProcess;

        //Look for remaining gazebo processes
        QString command = "pgrep -f gazebo";
        getGazPID->start("bash",QStringList() << "-c" << command);
        getGazPID->waitForFinished();

        //Kill remaining Gazebo processes
        QString output = getGazPID->readAllStandardOutput().trimmed();
        command = "pstree -p " + output + "  | awk -F'[()]' '{for(i=2;i<=NF;i+=2) print $i}' | sort -n | uniq | xargs kill -TERM";
        killGazebo->start("bash", QStringList()<<"-c"<<command);
        killGazebo->waitForFinished();
        //QThread::sleep(5);
    }

    //Set launcher active to false and reset parameters once stopped
    this->List_of_Launcher[type]->SetActive(false);
    this->List_of_Launcher[type]->resetLauncher();
}


 bool LauncherManager::CreateLauncher(LauncherType type, QProcess* process)
 {
     if(process == nullptr)
     {
         qDebug()<<"Process creation failed";
         return false;
     }
     else
     {
         //Set corresponding bash command to the launcher
         QString auxCommand;
         switch(type)
         {
         case RVIZZ2:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && rviz2";
             break;
         case RQT:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && rqt";
             break;
         case RQT_GRAPH:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && rqt_graph";
             break;
         case VIEW_FRAMES:
             auxCommand = "cd && cd " + workspace_dir->path() + " && ros2 run tf2_tools view_frames";
             break;
         case TELEOP:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 run teleop_twist_qt teleop_twist_qt";
             break;
         case FIRMWARE:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 run rosa_firmware rosa_driver --ros-args -p device_name:=/dev/ttyUSB0";
             break;
         case URDF:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 launch rosa_description rosa_urdf_launch.py";
             break;
         case LIDAR:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 launch urg_node2 urg_node2.launch.py";
             break;
         case SLAM:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && cd maps && ros2 launch rosa_description amcl_launch.py use_sim_time:=false slam:=True "
                                                                "slam_params:=" + workspace_dir->path() + "/src/rosa_description_Pablo/config/mapper_params_online_async.yaml "
                                                                "params_file:=" + workspace_dir->path() + "/src/rosa_description_Pablo/config/nav2_params.yaml";
             break;
         case NAVIGATION:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 launch rosa_description amcl_launch.py use_sim_time:=false map:=" + mapLoaded->fileName();
             break;
         case GAZEBO_SIM:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 launch rosa_description rosa_gazebo_launch.py use_sim_time:=true";
             break;
         case SLAM_SIM:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && cd maps && ros2 launch rosa_description amcl_launch.py use_sim_time:=true slam:=True "
                                                                "slam_params:=" + workspace_dir->path() + "/src/rosa_description_Pablo/config/mapper_params_online_async.yaml "
                                                                "params_file:=" + workspace_dir->path() + "/src/rosa_description_Pablo/config/nav2_params.yaml";
             break;
         case NAVIGATION_SIM:
             auxCommand = "cd && cd " + workspace_dir->path() + " && source install/setup.bash && ros2 launch rosa_description amcl_launch.py use_sim_time:=true map:=" + mapLoaded->fileName();
             break;
         default:
             qDebug()<<"Incorrect type, launcher can not be created";
             return false;
             break;
         }

         //Load parameters in the launcher
         List_of_Launcher[type]->LoadParameters(process, auxCommand);
         qDebug()<<"Process created";
         return true;
     }
 }


 bool LauncherManager::Launch(LauncherType type)
 {
     if(List_of_Launcher[type]->GetLauncherProcess() == nullptr)
     {
         qDebug()<<"No process to launch";
         return false;
     }
     else
     {
         //Execute process in the launcher with his command
         List_of_Launcher[type]->GetLauncherProcess()->start("bash", QStringList() << "-c" << List_of_Launcher[type]->GetCommand());
         List_of_Launcher[type]->GetLauncherProcess()->waitForStarted(-1);
         //Get the parent PID and set to the launcher atribute
         List_of_Launcher[type]->setParentPID(List_of_Launcher[type]->GetLauncherProcess()->processId());
         //Set launcher active
         List_of_Launcher[type]->SetActive(true);
         return true;
     }
 }

 bool LauncherManager::IsAnyActive()
 {
     bool result = false;

     for(int i = 0; i<NUMBER_OF_LAUNCHERS; i++)
     {
         result |= List_of_Launcher[i]->GetActive() ? true : false;
     }
     return result;
 }

 void LauncherManager::ShutdownLaunchers()
 {
     if(IsAnyActive())
     {
         for(int i = 0; i<NUMBER_OF_LAUNCHERS; i++)
         {
             LauncherType type = static_cast<LauncherType>(i);
             if(List_of_Launcher[type]->GetActive())
             {
                StopLauncher(type);
             }
         }
     }
 }

 Launcher* LauncherManager::GetLauncher(LauncherType type)
 {
     return List_of_Launcher[type];
 }

 void LauncherManager::SetWorkspaceDir(QString w_Path)
 {
     if (!w_Path.isEmpty())
     {
         workspace_dir = new QDir(w_Path);
     }

 }

 QDir* LauncherManager::GetWorkspacePath()
 {
     return workspace_dir;
 }

 void LauncherManager::SetMap(QString w_Path)
 {
     if (!w_Path.isEmpty())
     {
         mapLoaded = new QFile(w_Path);
     }

 }

 QFile* LauncherManager::GetMap()
 {
     return mapLoaded;
 }

 void LauncherManager::setActive(bool state, LauncherType type)
 {
     List_of_Launcher[type]->SetActive(state);
 }
