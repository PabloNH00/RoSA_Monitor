# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release

# Include any dependencies generated for this target.
include CMakeFiles/RoSA_Monitor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RoSA_Monitor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RoSA_Monitor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RoSA_Monitor.dir/flags.make

RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/resources.qrc
RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp: CMakeFiles/RoSA_Monitor_autogen.dir/AutoRcc_resources_EWIEGA46WW_Info.json
RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/img/UPM_logo_text.png
RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/img/ETSIDI_logo.png
RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp: /usr/lib/qt5/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for resources.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles/RoSA_Monitor_autogen.dir/AutoRcc_resources_EWIEGA46WW_Info.json Release

CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o: RoSA_Monitor_autogen/mocs_compilation.cpp
CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/RoSA_Monitor_autogen/mocs_compilation.cpp

CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/RoSA_Monitor_autogen/mocs_compilation.cpp > CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.i

CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/RoSA_Monitor_autogen/mocs_compilation.cpp -o CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.s

CMakeFiles/RoSA_Monitor.dir/main.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/main.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/main.cpp
CMakeFiles/RoSA_Monitor.dir/main.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RoSA_Monitor.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/main.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/main.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/main.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/main.cpp

CMakeFiles/RoSA_Monitor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/main.cpp > CMakeFiles/RoSA_Monitor.dir/main.cpp.i

CMakeFiles/RoSA_Monitor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/main.cpp -o CMakeFiles/RoSA_Monitor.dir/main.cpp.s

CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/mainwindow.cpp
CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/mainwindow.cpp

CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/mainwindow.cpp > CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.i

CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/mainwindow.cpp -o CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.s

CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/rosawindow.cpp
CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/rosawindow.cpp

CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/rosawindow.cpp > CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.i

CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/rosawindow.cpp -o CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.s

CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/simulationwindow.cpp
CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/simulationwindow.cpp

CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/simulationwindow.cpp > CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.i

CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/simulationwindow.cpp -o CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.s

CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/launchermanager.cpp
CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/launchermanager.cpp

CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/launchermanager.cpp > CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.i

CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/launchermanager.cpp -o CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.s

CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/Launcher.cpp
CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/Launcher.cpp

CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/Launcher.cpp > CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.i

CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/Launcher.cpp -o CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.s

CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/shelloutputwindow.cpp
CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/shelloutputwindow.cpp

CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/shelloutputwindow.cpp > CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.i

CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/shelloutputwindow.cpp -o CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.s

CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/selectrosacomponents.cpp
CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/selectrosacomponents.cpp

CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/selectrosacomponents.cpp > CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.i

CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/selectrosacomponents.cpp -o CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.s

CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o: /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/demowindow.cpp
CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/demowindow.cpp

CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/demowindow.cpp > CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.i

CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor/demowindow.cpp -o CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.s

CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o: CMakeFiles/RoSA_Monitor.dir/flags.make
CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o: RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp
CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o: CMakeFiles/RoSA_Monitor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o -MF CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o.d -o CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o -c /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp

CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp > CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.i

CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp -o CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.s

# Object files for target RoSA_Monitor
RoSA_Monitor_OBJECTS = \
"CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/main.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o" \
"CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o"

# External object files for target RoSA_Monitor
RoSA_Monitor_EXTERNAL_OBJECTS =

RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/mocs_compilation.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/main.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/mainwindow.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/rosawindow.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/simulationwindow.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/launchermanager.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/Launcher.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/shelloutputwindow.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/selectrosacomponents.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/demowindow.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp.o
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/build.make
RoSA_Monitor: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
RoSA_Monitor: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
RoSA_Monitor: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
RoSA_Monitor: CMakeFiles/RoSA_Monitor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable RoSA_Monitor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RoSA_Monitor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RoSA_Monitor.dir/build: RoSA_Monitor
.PHONY : CMakeFiles/RoSA_Monitor.dir/build

CMakeFiles/RoSA_Monitor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RoSA_Monitor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RoSA_Monitor.dir/clean

CMakeFiles/RoSA_Monitor.dir/depend: RoSA_Monitor_autogen/EWIEGA46WW/qrc_resources.cpp
	cd /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles/RoSA_Monitor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RoSA_Monitor.dir/depend

