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
- Restrictions about llaunching slam or nav. without FW URDF or LiDAR

## [Versión 0.1.7] 
During integration test

### Fixed
- Restrictions about llaunching slam or nav. only launch unnactive processes if at least one of them is unnactive
- esp32 button text and checked

## [Versión 0.1.8] 

### Added
- Launch RoSA button that opens a checkboxes window to select components of RoSA to launch

### Modified
- Debug and execution info now showed on status bar down the monitor screen
- GUI distribution layout for RoSA Components tab

## [Versión 0.1.9] 

### Added
- First documentation

### Fixed
- Minor fixes

## [Versión 0.1.10] 

### Added
- NODE_LIST button (only in simulation menu by the moment) that execute "ROS2 node list" and update the output every time is pressed
- Functions in shelloutputwindow to associate new process to a window and to clear the output

### Modified
- LauncherManager commands according to rosa_description/launch modifications

## [Versión 0.1.11] 

### Added
- Camera launcher for ROSA components
- NODE_LIST button for ROSA Menu

## [Versión 1.0.0] 02-11-2024
First completed version
  
### Added
- Demo Window to run STT-TTS demo
- Node list updated every time a launcher is executed or closed
  
### Modified
- Full screen windows
- Main window layout to resize images

### Fixed
- Workspace selection updates between menus
  - Directly from main menu to others
  - Trough a signal from others to main menu (to avoid specific menus to have a reference to main menu)
- SLAM launcher
- Minor details

## [Versión 1.0.1] 
  
### Added
- Startup verification looking for a workspace called "rosa_ws" in user's home directory to initialize workspace value

## [Versión 1.0.2] 
  
### Modified
- Previous menu only visible if any other menu is active
- Visuals of the buttons 
- Buttons's background set to green when active
- Select workspace and select map buttons coloured red if any selected 

## [Versión 1.0.3] 
  
### Modified
- Camera launcher to use the custom config file on rosa_robot repository

## [Versión 1.0.4] 
  
### Added
- Limitation to open SLAM when already navigating (it already was in code for the reverse case)

