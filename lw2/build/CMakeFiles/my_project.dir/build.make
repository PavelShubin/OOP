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
CMAKE_SOURCE_DIR = /home/pavel/OOP/lw2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/OOP/lw2/build

# Include any dependencies generated for this target.
include CMakeFiles/my_project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_project.dir/flags.make

CMakeFiles/my_project.dir/main.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/main.cpp.o: ../main.cpp
CMakeFiles/my_project.dir/main.cpp.o: CMakeFiles/my_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/OOP/lw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_project.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_project.dir/main.cpp.o -MF CMakeFiles/my_project.dir/main.cpp.o.d -o CMakeFiles/my_project.dir/main.cpp.o -c /home/pavel/OOP/lw2/main.cpp

CMakeFiles/my_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pavel/OOP/lw2/main.cpp > CMakeFiles/my_project.dir/main.cpp.i

CMakeFiles/my_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pavel/OOP/lw2/main.cpp -o CMakeFiles/my_project.dir/main.cpp.s

CMakeFiles/my_project.dir/money.cpp.o: CMakeFiles/my_project.dir/flags.make
CMakeFiles/my_project.dir/money.cpp.o: ../money.cpp
CMakeFiles/my_project.dir/money.cpp.o: CMakeFiles/my_project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/OOP/lw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_project.dir/money.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_project.dir/money.cpp.o -MF CMakeFiles/my_project.dir/money.cpp.o.d -o CMakeFiles/my_project.dir/money.cpp.o -c /home/pavel/OOP/lw2/money.cpp

CMakeFiles/my_project.dir/money.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/my_project.dir/money.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pavel/OOP/lw2/money.cpp > CMakeFiles/my_project.dir/money.cpp.i

CMakeFiles/my_project.dir/money.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/my_project.dir/money.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pavel/OOP/lw2/money.cpp -o CMakeFiles/my_project.dir/money.cpp.s

# Object files for target my_project
my_project_OBJECTS = \
"CMakeFiles/my_project.dir/main.cpp.o" \
"CMakeFiles/my_project.dir/money.cpp.o"

# External object files for target my_project
my_project_EXTERNAL_OBJECTS =

my_project: CMakeFiles/my_project.dir/main.cpp.o
my_project: CMakeFiles/my_project.dir/money.cpp.o
my_project: CMakeFiles/my_project.dir/build.make
my_project: CMakeFiles/my_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/OOP/lw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable my_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/my_project.dir/build: my_project
.PHONY : CMakeFiles/my_project.dir/build

CMakeFiles/my_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_project.dir/clean

CMakeFiles/my_project.dir/depend:
	cd /home/pavel/OOP/lw2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/OOP/lw2 /home/pavel/OOP/lw2 /home/pavel/OOP/lw2/build /home/pavel/OOP/lw2/build /home/pavel/OOP/lw2/build/CMakeFiles/my_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/my_project.dir/depend

