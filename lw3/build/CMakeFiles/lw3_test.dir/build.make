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
CMAKE_SOURCE_DIR = /home/pavel/OOP/lw3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pavel/OOP/lw3/build

# Include any dependencies generated for this target.
include CMakeFiles/lw3_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lw3_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lw3_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lw3_test.dir/flags.make

CMakeFiles/lw3_test.dir/test.cpp.o: CMakeFiles/lw3_test.dir/flags.make
CMakeFiles/lw3_test.dir/test.cpp.o: ../test.cpp
CMakeFiles/lw3_test.dir/test.cpp.o: CMakeFiles/lw3_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pavel/OOP/lw3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lw3_test.dir/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lw3_test.dir/test.cpp.o -MF CMakeFiles/lw3_test.dir/test.cpp.o.d -o CMakeFiles/lw3_test.dir/test.cpp.o -c /home/pavel/OOP/lw3/test.cpp

CMakeFiles/lw3_test.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lw3_test.dir/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pavel/OOP/lw3/test.cpp > CMakeFiles/lw3_test.dir/test.cpp.i

CMakeFiles/lw3_test.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lw3_test.dir/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pavel/OOP/lw3/test.cpp -o CMakeFiles/lw3_test.dir/test.cpp.s

# Object files for target lw3_test
lw3_test_OBJECTS = \
"CMakeFiles/lw3_test.dir/test.cpp.o"

# External object files for target lw3_test
lw3_test_EXTERNAL_OBJECTS =

lw3_test: CMakeFiles/lw3_test.dir/test.cpp.o
lw3_test: CMakeFiles/lw3_test.dir/build.make
lw3_test: liblw3_lib.a
lw3_test: CMakeFiles/lw3_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pavel/OOP/lw3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lw3_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lw3_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lw3_test.dir/build: lw3_test
.PHONY : CMakeFiles/lw3_test.dir/build

CMakeFiles/lw3_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lw3_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lw3_test.dir/clean

CMakeFiles/lw3_test.dir/depend:
	cd /home/pavel/OOP/lw3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pavel/OOP/lw3 /home/pavel/OOP/lw3 /home/pavel/OOP/lw3/build /home/pavel/OOP/lw3/build /home/pavel/OOP/lw3/build/CMakeFiles/lw3_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lw3_test.dir/depend
