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

# Utility rule file for RoSA_Monitor_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/RoSA_Monitor_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RoSA_Monitor_autogen.dir/progress.make

CMakeFiles/RoSA_Monitor_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target RoSA_Monitor"
	/usr/bin/cmake -E cmake_autogen /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles/RoSA_Monitor_autogen.dir/AutogenInfo.json Release

RoSA_Monitor_autogen: CMakeFiles/RoSA_Monitor_autogen
RoSA_Monitor_autogen: CMakeFiles/RoSA_Monitor_autogen.dir/build.make
.PHONY : RoSA_Monitor_autogen

# Rule to build all files generated by this target.
CMakeFiles/RoSA_Monitor_autogen.dir/build: RoSA_Monitor_autogen
.PHONY : CMakeFiles/RoSA_Monitor_autogen.dir/build

CMakeFiles/RoSA_Monitor_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RoSA_Monitor_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RoSA_Monitor_autogen.dir/clean

CMakeFiles/RoSA_Monitor_autogen.dir/depend:
	cd /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor /home/pablonh-ubuntu/RoSA_monitor/RoSA_Monitor /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release /home/pablonh-ubuntu/RoSA_monitor/build-RoSA_Monitor-Desktop-Release/CMakeFiles/RoSA_Monitor_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RoSA_Monitor_autogen.dir/depend

