# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/pi/raspi_project_16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/raspi_project_16

# Include any dependencies generated for this target.
include CMakeFiles/soundModule.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/soundModule.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/soundModule.dir/flags.make

CMakeFiles/soundModule.dir/soundModule.cpp.o: CMakeFiles/soundModule.dir/flags.make
CMakeFiles/soundModule.dir/soundModule.cpp.o: soundModule.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/soundModule.dir/soundModule.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/soundModule.dir/soundModule.cpp.o -c /home/pi/raspi_project_16/soundModule.cpp

CMakeFiles/soundModule.dir/soundModule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/soundModule.dir/soundModule.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/raspi_project_16/soundModule.cpp > CMakeFiles/soundModule.dir/soundModule.cpp.i

CMakeFiles/soundModule.dir/soundModule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/soundModule.dir/soundModule.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/raspi_project_16/soundModule.cpp -o CMakeFiles/soundModule.dir/soundModule.cpp.s

# Object files for target soundModule
soundModule_OBJECTS = \
"CMakeFiles/soundModule.dir/soundModule.cpp.o"

# External object files for target soundModule
soundModule_EXTERNAL_OBJECTS =

soundModule: CMakeFiles/soundModule.dir/soundModule.cpp.o
soundModule: CMakeFiles/soundModule.dir/build.make
soundModule: CMakeFiles/soundModule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/raspi_project_16/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable soundModule"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/soundModule.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/soundModule.dir/build: soundModule

.PHONY : CMakeFiles/soundModule.dir/build

CMakeFiles/soundModule.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/soundModule.dir/cmake_clean.cmake
.PHONY : CMakeFiles/soundModule.dir/clean

CMakeFiles/soundModule.dir/depend:
	cd /home/pi/raspi_project_16 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/raspi_project_16 /home/pi/raspi_project_16 /home/pi/raspi_project_16 /home/pi/raspi_project_16 /home/pi/raspi_project_16/CMakeFiles/soundModule.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/soundModule.dir/depend
