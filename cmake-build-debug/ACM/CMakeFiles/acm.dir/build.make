# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ning/Project/Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ning/Project/Algorithm/cmake-build-debug

# Include any dependencies generated for this target.
include ACM/CMakeFiles/acm.dir/depend.make

# Include the progress variables for this target.
include ACM/CMakeFiles/acm.dir/progress.make

# Include the compile flags for this target's objects.
include ACM/CMakeFiles/acm.dir/flags.make

ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o: ACM/CMakeFiles/acm.dir/flags.make
ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o: ../ACM/Stack_Queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/acm.dir/Stack_Queue.cpp.o -c /Users/ning/Project/Algorithm/ACM/Stack_Queue.cpp

ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/acm.dir/Stack_Queue.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/ACM/Stack_Queue.cpp > CMakeFiles/acm.dir/Stack_Queue.cpp.i

ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/acm.dir/Stack_Queue.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/ACM/Stack_Queue.cpp -o CMakeFiles/acm.dir/Stack_Queue.cpp.s

ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.requires:

.PHONY : ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.requires

ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.provides: ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.requires
	$(MAKE) -f ACM/CMakeFiles/acm.dir/build.make ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.provides.build
.PHONY : ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.provides

ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.provides.build: ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o


ACM/CMakeFiles/acm.dir/Tree.cpp.o: ACM/CMakeFiles/acm.dir/flags.make
ACM/CMakeFiles/acm.dir/Tree.cpp.o: ../ACM/Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ACM/CMakeFiles/acm.dir/Tree.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/acm.dir/Tree.cpp.o -c /Users/ning/Project/Algorithm/ACM/Tree.cpp

ACM/CMakeFiles/acm.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/acm.dir/Tree.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/ACM/Tree.cpp > CMakeFiles/acm.dir/Tree.cpp.i

ACM/CMakeFiles/acm.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/acm.dir/Tree.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/ACM/Tree.cpp -o CMakeFiles/acm.dir/Tree.cpp.s

ACM/CMakeFiles/acm.dir/Tree.cpp.o.requires:

.PHONY : ACM/CMakeFiles/acm.dir/Tree.cpp.o.requires

ACM/CMakeFiles/acm.dir/Tree.cpp.o.provides: ACM/CMakeFiles/acm.dir/Tree.cpp.o.requires
	$(MAKE) -f ACM/CMakeFiles/acm.dir/build.make ACM/CMakeFiles/acm.dir/Tree.cpp.o.provides.build
.PHONY : ACM/CMakeFiles/acm.dir/Tree.cpp.o.provides

ACM/CMakeFiles/acm.dir/Tree.cpp.o.provides.build: ACM/CMakeFiles/acm.dir/Tree.cpp.o


ACM/CMakeFiles/acm.dir/Graph.cpp.o: ACM/CMakeFiles/acm.dir/flags.make
ACM/CMakeFiles/acm.dir/Graph.cpp.o: ../ACM/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object ACM/CMakeFiles/acm.dir/Graph.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/acm.dir/Graph.cpp.o -c /Users/ning/Project/Algorithm/ACM/Graph.cpp

ACM/CMakeFiles/acm.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/acm.dir/Graph.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/ACM/Graph.cpp > CMakeFiles/acm.dir/Graph.cpp.i

ACM/CMakeFiles/acm.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/acm.dir/Graph.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/ACM/Graph.cpp -o CMakeFiles/acm.dir/Graph.cpp.s

ACM/CMakeFiles/acm.dir/Graph.cpp.o.requires:

.PHONY : ACM/CMakeFiles/acm.dir/Graph.cpp.o.requires

ACM/CMakeFiles/acm.dir/Graph.cpp.o.provides: ACM/CMakeFiles/acm.dir/Graph.cpp.o.requires
	$(MAKE) -f ACM/CMakeFiles/acm.dir/build.make ACM/CMakeFiles/acm.dir/Graph.cpp.o.provides.build
.PHONY : ACM/CMakeFiles/acm.dir/Graph.cpp.o.provides

ACM/CMakeFiles/acm.dir/Graph.cpp.o.provides.build: ACM/CMakeFiles/acm.dir/Graph.cpp.o


ACM/CMakeFiles/acm.dir/test_acm.cpp.o: ACM/CMakeFiles/acm.dir/flags.make
ACM/CMakeFiles/acm.dir/test_acm.cpp.o: ../ACM/test_acm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object ACM/CMakeFiles/acm.dir/test_acm.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/acm.dir/test_acm.cpp.o -c /Users/ning/Project/Algorithm/ACM/test_acm.cpp

ACM/CMakeFiles/acm.dir/test_acm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/acm.dir/test_acm.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/ACM/test_acm.cpp > CMakeFiles/acm.dir/test_acm.cpp.i

ACM/CMakeFiles/acm.dir/test_acm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/acm.dir/test_acm.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/ACM/test_acm.cpp -o CMakeFiles/acm.dir/test_acm.cpp.s

ACM/CMakeFiles/acm.dir/test_acm.cpp.o.requires:

.PHONY : ACM/CMakeFiles/acm.dir/test_acm.cpp.o.requires

ACM/CMakeFiles/acm.dir/test_acm.cpp.o.provides: ACM/CMakeFiles/acm.dir/test_acm.cpp.o.requires
	$(MAKE) -f ACM/CMakeFiles/acm.dir/build.make ACM/CMakeFiles/acm.dir/test_acm.cpp.o.provides.build
.PHONY : ACM/CMakeFiles/acm.dir/test_acm.cpp.o.provides

ACM/CMakeFiles/acm.dir/test_acm.cpp.o.provides.build: ACM/CMakeFiles/acm.dir/test_acm.cpp.o


# Object files for target acm
acm_OBJECTS = \
"CMakeFiles/acm.dir/Stack_Queue.cpp.o" \
"CMakeFiles/acm.dir/Tree.cpp.o" \
"CMakeFiles/acm.dir/Graph.cpp.o" \
"CMakeFiles/acm.dir/test_acm.cpp.o"

# External object files for target acm
acm_EXTERNAL_OBJECTS =

ACM/acm: ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o
ACM/acm: ACM/CMakeFiles/acm.dir/Tree.cpp.o
ACM/acm: ACM/CMakeFiles/acm.dir/Graph.cpp.o
ACM/acm: ACM/CMakeFiles/acm.dir/test_acm.cpp.o
ACM/acm: ACM/CMakeFiles/acm.dir/build.make
ACM/acm: ACM/CMakeFiles/acm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable acm"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/acm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ACM/CMakeFiles/acm.dir/build: ACM/acm

.PHONY : ACM/CMakeFiles/acm.dir/build

ACM/CMakeFiles/acm.dir/requires: ACM/CMakeFiles/acm.dir/Stack_Queue.cpp.o.requires
ACM/CMakeFiles/acm.dir/requires: ACM/CMakeFiles/acm.dir/Tree.cpp.o.requires
ACM/CMakeFiles/acm.dir/requires: ACM/CMakeFiles/acm.dir/Graph.cpp.o.requires
ACM/CMakeFiles/acm.dir/requires: ACM/CMakeFiles/acm.dir/test_acm.cpp.o.requires

.PHONY : ACM/CMakeFiles/acm.dir/requires

ACM/CMakeFiles/acm.dir/clean:
	cd /Users/ning/Project/Algorithm/cmake-build-debug/ACM && $(CMAKE_COMMAND) -P CMakeFiles/acm.dir/cmake_clean.cmake
.PHONY : ACM/CMakeFiles/acm.dir/clean

ACM/CMakeFiles/acm.dir/depend:
	cd /Users/ning/Project/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Project/Algorithm /Users/ning/Project/Algorithm/ACM /Users/ning/Project/Algorithm/cmake-build-debug /Users/ning/Project/Algorithm/cmake-build-debug/ACM /Users/ning/Project/Algorithm/cmake-build-debug/ACM/CMakeFiles/acm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ACM/CMakeFiles/acm.dir/depend

