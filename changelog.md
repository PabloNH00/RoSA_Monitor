# Changelog RoSA Monitor

## [Version 0.0.1]
### Added
- Created project with a main window with two buttons, "RoSA Menu" and "Simulation Menu"

## [Versión 0.0.2] 
### Added
- Simulation window for simulation menu
- Buttons for launchin Gazebo and SLAM

### Modified
- Main window code to show simulation menu when button is pressed

## [Versión 0.0.3]
### Added
- Debug tools (rviz2, rqt and rqt_graph) buttons to launch them
  
### Modified
- GUI distribution layout

## [Versión 0.0.4]
### Added
- Launcher interface class 
- Launcher manager to separate the treatment of the launchers from the windows
  
### Modified
- Code structure to integrate Launcher and Launcher manager classes

## [Versión 0.0.5]
### Added
- /img directory to root folder of the project
- Images to main window
- Selector of workspace and creation of /maps directory for saving results of SLAM
- teleop_twist and transform tree buttons to debug tools in simulation window
- Go back to main menu and return to current menu buttons

## [Versión 0.0.6]
### Added
- Navigation button to simulation window
- Map selector for navigation launcher

### Fixed
- Trying to access to a null workspace pointer when simulation window is closed from main window.
  
### Modified
- GUI structure of simulation window to resize widgets with the window

## [Versión 0.1.0] 03-08-2024
Simulation window finished, under review
  
### Modified
- Cleaned code and project

### Fixed
- Problems with checked status in release version

## [Versión 0.1.1] 

### Added
- Rosa Window for RoSA menu
- Interaction between main window and rosa window
- RoSA Firmware button, which launch rqt only for testing  

### Modified
- Simulation window GUI layout

### Fixed
- Now you can cancel workspace selection when requested from simulation window, same with rosa window
- 
## [Versión 0.1.2] 

### Added
- TabWidget that open tabs with the console output for each launcher activated
- ShellOutputWindow: Window instanced for each tab with a plain text widget for printing the console std output
- Management of tabs to close them when its launcher closes

### Fixed
- Previous menu button now show selected menu window even if it wasn't minimized for previous click on main menu button

## [Versión 0.1.3] 

### Added
- Launchers for RoSA URDF and Hokuyo LiDAr
- New default tab for RoSA menu based on Simulation menu

### Modified
- RoSA Window GUI layout

## [Versión 0.1.4] 
During integration test
### Fixed
- Asked to launch firmware when gazebo instead of firmware is not launched

## [Versión 0.1.5] 
During integration test
### Fixed
- Launchers for SLAM and NAVIGATION now different in sim and RoSA due to "use_sim_time" param
- Rviz tab close when launcher is stoped for a question to user

## [Versión 0.1.6] 
During integration test
### Added
- Button on RoSA debug tools for esp32 monitor

### Fixed
- Restrictions about llaunchin slam or nav. without FW URDF or LiDAR