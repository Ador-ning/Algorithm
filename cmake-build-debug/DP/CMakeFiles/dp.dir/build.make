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
include DP/CMakeFiles/dp.dir/depend.make

# Include the progress variables for this target.
include DP/CMakeFiles/dp.dir/progress.make

# Include the compile flags for this target's objects.
include DP/CMakeFiles/dp.dir/flags.make

DP/CMakeFiles/dp.dir/BackTracing.cpp.o: DP/CMakeFiles/dp.dir/flags.make
DP/CMakeFiles/dp.dir/BackTracing.cpp.o: ../DP/BackTracing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DP/CMakeFiles/dp.dir/BackTracing.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dp.dir/BackTracing.cpp.o -c /Users/ning/Project/Algorithm/DP/BackTracing.cpp

DP/CMakeFiles/dp.dir/BackTracing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp.dir/BackTracing.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/DP/BackTracing.cpp > CMakeFiles/dp.dir/BackTracing.cpp.i

DP/CMakeFiles/dp.dir/BackTracing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp.dir/BackTracing.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/DP/BackTracing.cpp -o CMakeFiles/dp.dir/BackTracing.cpp.s

DP/CMakeFiles/dp.dir/BackTracing.cpp.o.requires:

.PHONY : DP/CMakeFiles/dp.dir/BackTracing.cpp.o.requires

DP/CMakeFiles/dp.dir/BackTracing.cpp.o.provides: DP/CMakeFiles/dp.dir/BackTracing.cpp.o.requires
	$(MAKE) -f DP/CMakeFiles/dp.dir/build.make DP/CMakeFiles/dp.dir/BackTracing.cpp.o.provides.build
.PHONY : DP/CMakeFiles/dp.dir/BackTracing.cpp.o.provides

DP/CMakeFiles/dp.dir/BackTracing.cpp.o.provides.build: DP/CMakeFiles/dp.dir/BackTracing.cpp.o


DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o: DP/CMakeFiles/dp.dir/flags.make
DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o: ../DP/DynamicProgramming.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dp.dir/DynamicProgramming.cpp.o -c /Users/ning/Project/Algorithm/DP/DynamicProgramming.cpp

DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp.dir/DynamicProgramming.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/DP/DynamicProgramming.cpp > CMakeFiles/dp.dir/DynamicProgramming.cpp.i

DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp.dir/DynamicProgramming.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/DP/DynamicProgramming.cpp -o CMakeFiles/dp.dir/DynamicProgramming.cpp.s

DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.requires:

.PHONY : DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.requires

DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.provides: DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.requires
	$(MAKE) -f DP/CMakeFiles/dp.dir/build.make DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.provides.build
.PHONY : DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.provides

DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.provides.build: DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o


DP/CMakeFiles/dp.dir/Fibonacci.cpp.o: DP/CMakeFiles/dp.dir/flags.make
DP/CMakeFiles/dp.dir/Fibonacci.cpp.o: ../DP/Fibonacci.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object DP/CMakeFiles/dp.dir/Fibonacci.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dp.dir/Fibonacci.cpp.o -c /Users/ning/Project/Algorithm/DP/Fibonacci.cpp

DP/CMakeFiles/dp.dir/Fibonacci.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp.dir/Fibonacci.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/DP/Fibonacci.cpp > CMakeFiles/dp.dir/Fibonacci.cpp.i

DP/CMakeFiles/dp.dir/Fibonacci.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp.dir/Fibonacci.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/DP/Fibonacci.cpp -o CMakeFiles/dp.dir/Fibonacci.cpp.s

DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.requires:

.PHONY : DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.requires

DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.provides: DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.requires
	$(MAKE) -f DP/CMakeFiles/dp.dir/build.make DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.provides.build
.PHONY : DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.provides

DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.provides.build: DP/CMakeFiles/dp.dir/Fibonacci.cpp.o


DP/CMakeFiles/dp.dir/test_dp.cpp.o: DP/CMakeFiles/dp.dir/flags.make
DP/CMakeFiles/dp.dir/test_dp.cpp.o: ../DP/test_dp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object DP/CMakeFiles/dp.dir/test_dp.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dp.dir/test_dp.cpp.o -c /Users/ning/Project/Algorithm/DP/test_dp.cpp

DP/CMakeFiles/dp.dir/test_dp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dp.dir/test_dp.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/DP/test_dp.cpp > CMakeFiles/dp.dir/test_dp.cpp.i

DP/CMakeFiles/dp.dir/test_dp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dp.dir/test_dp.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/DP/test_dp.cpp -o CMakeFiles/dp.dir/test_dp.cpp.s

DP/CMakeFiles/dp.dir/test_dp.cpp.o.requires:

.PHONY : DP/CMakeFiles/dp.dir/test_dp.cpp.o.requires

DP/CMakeFiles/dp.dir/test_dp.cpp.o.provides: DP/CMakeFiles/dp.dir/test_dp.cpp.o.requires
	$(MAKE) -f DP/CMakeFiles/dp.dir/build.make DP/CMakeFiles/dp.dir/test_dp.cpp.o.provides.build
.PHONY : DP/CMakeFiles/dp.dir/test_dp.cpp.o.provides

DP/CMakeFiles/dp.dir/test_dp.cpp.o.provides.build: DP/CMakeFiles/dp.dir/test_dp.cpp.o


# Object files for target dp
dp_OBJECTS = \
"CMakeFiles/dp.dir/BackTracing.cpp.o" \
"CMakeFiles/dp.dir/DynamicProgramming.cpp.o" \
"CMakeFiles/dp.dir/Fibonacci.cpp.o" \
"CMakeFiles/dp.dir/test_dp.cpp.o"

# External object files for target dp
dp_EXTERNAL_OBJECTS =

DP/dp: DP/CMakeFiles/dp.dir/BackTracing.cpp.o
DP/dp: DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o
DP/dp: DP/CMakeFiles/dp.dir/Fibonacci.cpp.o
DP/dp: DP/CMakeFiles/dp.dir/test_dp.cpp.o
DP/dp: DP/CMakeFiles/dp.dir/build.make
DP/dp: DP/CMakeFiles/dp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable dp"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DP/CMakeFiles/dp.dir/build: DP/dp

.PHONY : DP/CMakeFiles/dp.dir/build

DP/CMakeFiles/dp.dir/requires: DP/CMakeFiles/dp.dir/BackTracing.cpp.o.requires
DP/CMakeFiles/dp.dir/requires: DP/CMakeFiles/dp.dir/DynamicProgramming.cpp.o.requires
DP/CMakeFiles/dp.dir/requires: DP/CMakeFiles/dp.dir/Fibonacci.cpp.o.requires
DP/CMakeFiles/dp.dir/requires: DP/CMakeFiles/dp.dir/test_dp.cpp.o.requires

.PHONY : DP/CMakeFiles/dp.dir/requires

DP/CMakeFiles/dp.dir/clean:
	cd /Users/ning/Project/Algorithm/cmake-build-debug/DP && $(CMAKE_COMMAND) -P CMakeFiles/dp.dir/cmake_clean.cmake
.PHONY : DP/CMakeFiles/dp.dir/clean

DP/CMakeFiles/dp.dir/depend:
	cd /Users/ning/Project/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Project/Algorithm /Users/ning/Project/Algorithm/DP /Users/ning/Project/Algorithm/cmake-build-debug /Users/ning/Project/Algorithm/cmake-build-debug/DP /Users/ning/Project/Algorithm/cmake-build-debug/DP/CMakeFiles/dp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DP/CMakeFiles/dp.dir/depend

