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
CMAKE_SOURCE_DIR = /home/pavel/OOP/lw5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/OOP/lw5/tmp

# Include any dependencies generated for this target.
include CMakeFiles/test_l5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_l5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_l5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_l5.dir/flags.make

CMakeFiles/test_l5.dir/test/main.cpp.o: CMakeFiles/test_l5.dir/flags.make
CMakeFiles/test_l5.dir/test/main.cpp.o: ../test/main.cpp
CMakeFiles/test_l5.dir/test/main.cpp.o: CMakeFiles/test_l5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/OOP/lw5/tmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_l5.dir/test/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_l5.dir/test/main.cpp.o -MF CMakeFiles/test_l5.dir/test/main.cpp.o.d -o CMakeFiles/test_l5.dir/test/main.cpp.o -c /home/pavel/OOP/lw5/test/main.cpp

CMakeFiles/test_l5.dir/test/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_l5.dir/test/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pavel/OOP/lw5/test/main.cpp > CMakeFiles/test_l5.dir/test/main.cpp.i

CMakeFiles/test_l5.dir/test/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_l5.dir/test/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pavel/OOP/lw5/test/main.cpp -o CMakeFiles/test_l5.dir/test/main.cpp.s

# Object files for target test_l5
test_l5_OBJECTS = \
"CMakeFiles/test_l5.dir/test/main.cpp.o"

# External object files for target test_l5
test_l5_EXTERNAL_OBJECTS =

test_l5: CMakeFiles/test_l5.dir/test/main.cpp.o
test_l5: CMakeFiles/test_l5.dir/build.make
test_l5: lib/libgtest_main.a
test_l5: lib/libgtest.a
test_l5: CMakeFiles/test_l5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/OOP/lw5/tmp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_l5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_l5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_l5.dir/build: test_l5
.PHONY : CMakeFiles/test_l5.dir/build

CMakeFiles/test_l5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_l5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_l5.dir/clean

CMakeFiles/test_l5.dir/depend:
	cd /home/pavel/OOP/lw5/tmp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/OOP/lw5 /home/pavel/OOP/lw5 /home/pavel/OOP/lw5/tmp /home/pavel/OOP/lw5/tmp /home/pavel/OOP/lw5/tmp/CMakeFiles/test_l5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_l5.dir/depend

