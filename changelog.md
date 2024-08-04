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
