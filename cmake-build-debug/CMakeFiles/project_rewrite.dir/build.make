# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/137/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/137/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/piotr/Documents/c/computer-networks/project-rewrite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project_rewrite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project_rewrite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project_rewrite.dir/flags.make

CMakeFiles/project_rewrite.dir/main.c.o: CMakeFiles/project_rewrite.dir/flags.make
CMakeFiles/project_rewrite.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project_rewrite.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project_rewrite.dir/main.c.o   -c /home/piotr/Documents/c/computer-networks/project-rewrite/main.c

CMakeFiles/project_rewrite.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project_rewrite.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/piotr/Documents/c/computer-networks/project-rewrite/main.c > CMakeFiles/project_rewrite.dir/main.c.i

CMakeFiles/project_rewrite.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project_rewrite.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/piotr/Documents/c/computer-networks/project-rewrite/main.c -o CMakeFiles/project_rewrite.dir/main.c.s

# Object files for target project_rewrite
project_rewrite_OBJECTS = \
"CMakeFiles/project_rewrite.dir/main.c.o"

# External object files for target project_rewrite
project_rewrite_EXTERNAL_OBJECTS =

project_rewrite: CMakeFiles/project_rewrite.dir/main.c.o
project_rewrite: CMakeFiles/project_rewrite.dir/build.make
project_rewrite: CMakeFiles/project_rewrite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable project_rewrite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project_rewrite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project_rewrite.dir/build: project_rewrite

.PHONY : CMakeFiles/project_rewrite.dir/build

CMakeFiles/project_rewrite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project_rewrite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project_rewrite.dir/clean

CMakeFiles/project_rewrite.dir/depend:
	cd /home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/piotr/Documents/c/computer-networks/project-rewrite /home/piotr/Documents/c/computer-networks/project-rewrite /home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug /home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug /home/piotr/Documents/c/computer-networks/project-rewrite/cmake-build-debug/CMakeFiles/project_rewrite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project_rewrite.dir/depend
