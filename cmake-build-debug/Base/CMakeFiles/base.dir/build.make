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
include Base/CMakeFiles/base.dir/depend.make

# Include the progress variables for this target.
include Base/CMakeFiles/base.dir/progress.make

# Include the compile flags for this target's objects.
include Base/CMakeFiles/base.dir/flags.make

Base/CMakeFiles/base.dir/BinaryTree.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/BinaryTree.cpp.o: ../Base/BinaryTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Base/CMakeFiles/base.dir/BinaryTree.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/BinaryTree.cpp.o -c /Users/ning/Project/Algorithm/Base/BinaryTree.cpp

Base/CMakeFiles/base.dir/BinaryTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/BinaryTree.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/BinaryTree.cpp > CMakeFiles/base.dir/BinaryTree.cpp.i

Base/CMakeFiles/base.dir/BinaryTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/BinaryTree.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/BinaryTree.cpp -o CMakeFiles/base.dir/BinaryTree.cpp.s

Base/CMakeFiles/base.dir/BinaryTree.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/BinaryTree.cpp.o.requires

Base/CMakeFiles/base.dir/BinaryTree.cpp.o.provides: Base/CMakeFiles/base.dir/BinaryTree.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/BinaryTree.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/BinaryTree.cpp.o.provides

Base/CMakeFiles/base.dir/BinaryTree.cpp.o.provides.build: Base/CMakeFiles/base.dir/BinaryTree.cpp.o


Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o: ../Base/BinaryTreeProblem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/BinaryTreeProblem.cpp.o -c /Users/ning/Project/Algorithm/Base/BinaryTreeProblem.cpp

Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/BinaryTreeProblem.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/BinaryTreeProblem.cpp > CMakeFiles/base.dir/BinaryTreeProblem.cpp.i

Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/BinaryTreeProblem.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/BinaryTreeProblem.cpp -o CMakeFiles/base.dir/BinaryTreeProblem.cpp.s

Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.requires

Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.provides: Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.provides

Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.provides.build: Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o


Base/CMakeFiles/base.dir/LinkList.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/LinkList.cpp.o: ../Base/LinkList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Base/CMakeFiles/base.dir/LinkList.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/LinkList.cpp.o -c /Users/ning/Project/Algorithm/Base/LinkList.cpp

Base/CMakeFiles/base.dir/LinkList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/LinkList.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/LinkList.cpp > CMakeFiles/base.dir/LinkList.cpp.i

Base/CMakeFiles/base.dir/LinkList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/LinkList.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/LinkList.cpp -o CMakeFiles/base.dir/LinkList.cpp.s

Base/CMakeFiles/base.dir/LinkList.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/LinkList.cpp.o.requires

Base/CMakeFiles/base.dir/LinkList.cpp.o.provides: Base/CMakeFiles/base.dir/LinkList.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/LinkList.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/LinkList.cpp.o.provides

Base/CMakeFiles/base.dir/LinkList.cpp.o.provides.build: Base/CMakeFiles/base.dir/LinkList.cpp.o


Base/CMakeFiles/base.dir/LinkListProblem.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/LinkListProblem.cpp.o: ../Base/LinkListProblem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Base/CMakeFiles/base.dir/LinkListProblem.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/LinkListProblem.cpp.o -c /Users/ning/Project/Algorithm/Base/LinkListProblem.cpp

Base/CMakeFiles/base.dir/LinkListProblem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/LinkListProblem.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/LinkListProblem.cpp > CMakeFiles/base.dir/LinkListProblem.cpp.i

Base/CMakeFiles/base.dir/LinkListProblem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/LinkListProblem.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/LinkListProblem.cpp -o CMakeFiles/base.dir/LinkListProblem.cpp.s

Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.requires

Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.provides: Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.provides

Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.provides.build: Base/CMakeFiles/base.dir/LinkListProblem.cpp.o


Base/CMakeFiles/base.dir/UnionFind.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/UnionFind.cpp.o: ../Base/UnionFind.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Base/CMakeFiles/base.dir/UnionFind.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/UnionFind.cpp.o -c /Users/ning/Project/Algorithm/Base/UnionFind.cpp

Base/CMakeFiles/base.dir/UnionFind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/UnionFind.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/UnionFind.cpp > CMakeFiles/base.dir/UnionFind.cpp.i

Base/CMakeFiles/base.dir/UnionFind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/UnionFind.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/UnionFind.cpp -o CMakeFiles/base.dir/UnionFind.cpp.s

Base/CMakeFiles/base.dir/UnionFind.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/UnionFind.cpp.o.requires

Base/CMakeFiles/base.dir/UnionFind.cpp.o.provides: Base/CMakeFiles/base.dir/UnionFind.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/UnionFind.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/UnionFind.cpp.o.provides

Base/CMakeFiles/base.dir/UnionFind.cpp.o.provides.build: Base/CMakeFiles/base.dir/UnionFind.cpp.o


Base/CMakeFiles/base.dir/IntervalTree.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/IntervalTree.cpp.o: ../Base/IntervalTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object Base/CMakeFiles/base.dir/IntervalTree.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/IntervalTree.cpp.o -c /Users/ning/Project/Algorithm/Base/IntervalTree.cpp

Base/CMakeFiles/base.dir/IntervalTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/IntervalTree.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/IntervalTree.cpp > CMakeFiles/base.dir/IntervalTree.cpp.i

Base/CMakeFiles/base.dir/IntervalTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/IntervalTree.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/IntervalTree.cpp -o CMakeFiles/base.dir/IntervalTree.cpp.s

Base/CMakeFiles/base.dir/IntervalTree.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/IntervalTree.cpp.o.requires

Base/CMakeFiles/base.dir/IntervalTree.cpp.o.provides: Base/CMakeFiles/base.dir/IntervalTree.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/IntervalTree.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/IntervalTree.cpp.o.provides

Base/CMakeFiles/base.dir/IntervalTree.cpp.o.provides.build: Base/CMakeFiles/base.dir/IntervalTree.cpp.o


Base/CMakeFiles/base.dir/HashSet.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/HashSet.cpp.o: ../Base/HashSet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object Base/CMakeFiles/base.dir/HashSet.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/HashSet.cpp.o -c /Users/ning/Project/Algorithm/Base/HashSet.cpp

Base/CMakeFiles/base.dir/HashSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/HashSet.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/HashSet.cpp > CMakeFiles/base.dir/HashSet.cpp.i

Base/CMakeFiles/base.dir/HashSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/HashSet.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/HashSet.cpp -o CMakeFiles/base.dir/HashSet.cpp.s

Base/CMakeFiles/base.dir/HashSet.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/HashSet.cpp.o.requires

Base/CMakeFiles/base.dir/HashSet.cpp.o.provides: Base/CMakeFiles/base.dir/HashSet.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/HashSet.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/HashSet.cpp.o.provides

Base/CMakeFiles/base.dir/HashSet.cpp.o.provides.build: Base/CMakeFiles/base.dir/HashSet.cpp.o


Base/CMakeFiles/base.dir/BFS.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/BFS.cpp.o: ../Base/BFS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object Base/CMakeFiles/base.dir/BFS.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/BFS.cpp.o -c /Users/ning/Project/Algorithm/Base/BFS.cpp

Base/CMakeFiles/base.dir/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/BFS.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/BFS.cpp > CMakeFiles/base.dir/BFS.cpp.i

Base/CMakeFiles/base.dir/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/BFS.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/BFS.cpp -o CMakeFiles/base.dir/BFS.cpp.s

Base/CMakeFiles/base.dir/BFS.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/BFS.cpp.o.requires

Base/CMakeFiles/base.dir/BFS.cpp.o.provides: Base/CMakeFiles/base.dir/BFS.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/BFS.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/BFS.cpp.o.provides

Base/CMakeFiles/base.dir/BFS.cpp.o.provides.build: Base/CMakeFiles/base.dir/BFS.cpp.o


Base/CMakeFiles/base.dir/Graph.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/Graph.cpp.o: ../Base/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object Base/CMakeFiles/base.dir/Graph.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Graph.cpp.o -c /Users/ning/Project/Algorithm/Base/Graph.cpp

Base/CMakeFiles/base.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Graph.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/Graph.cpp > CMakeFiles/base.dir/Graph.cpp.i

Base/CMakeFiles/base.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Graph.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/Graph.cpp -o CMakeFiles/base.dir/Graph.cpp.s

Base/CMakeFiles/base.dir/Graph.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/Graph.cpp.o.requires

Base/CMakeFiles/base.dir/Graph.cpp.o.provides: Base/CMakeFiles/base.dir/Graph.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/Graph.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/Graph.cpp.o.provides

Base/CMakeFiles/base.dir/Graph.cpp.o.provides.build: Base/CMakeFiles/base.dir/Graph.cpp.o


Base/CMakeFiles/base.dir/Trie.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/Trie.cpp.o: ../Base/Trie.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object Base/CMakeFiles/base.dir/Trie.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/Trie.cpp.o -c /Users/ning/Project/Algorithm/Base/Trie.cpp

Base/CMakeFiles/base.dir/Trie.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/Trie.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/Trie.cpp > CMakeFiles/base.dir/Trie.cpp.i

Base/CMakeFiles/base.dir/Trie.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/Trie.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/Trie.cpp -o CMakeFiles/base.dir/Trie.cpp.s

Base/CMakeFiles/base.dir/Trie.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/Trie.cpp.o.requires

Base/CMakeFiles/base.dir/Trie.cpp.o.provides: Base/CMakeFiles/base.dir/Trie.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/Trie.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/Trie.cpp.o.provides

Base/CMakeFiles/base.dir/Trie.cpp.o.provides.build: Base/CMakeFiles/base.dir/Trie.cpp.o


Base/CMakeFiles/base.dir/test_base.cpp.o: Base/CMakeFiles/base.dir/flags.make
Base/CMakeFiles/base.dir/test_base.cpp.o: ../Base/test_base.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object Base/CMakeFiles/base.dir/test_base.cpp.o"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/base.dir/test_base.cpp.o -c /Users/ning/Project/Algorithm/Base/test_base.cpp

Base/CMakeFiles/base.dir/test_base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/base.dir/test_base.cpp.i"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ning/Project/Algorithm/Base/test_base.cpp > CMakeFiles/base.dir/test_base.cpp.i

Base/CMakeFiles/base.dir/test_base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/base.dir/test_base.cpp.s"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && /usr/local/Cellar/gcc/8.1.0/bin/g++-8 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ning/Project/Algorithm/Base/test_base.cpp -o CMakeFiles/base.dir/test_base.cpp.s

Base/CMakeFiles/base.dir/test_base.cpp.o.requires:

.PHONY : Base/CMakeFiles/base.dir/test_base.cpp.o.requires

Base/CMakeFiles/base.dir/test_base.cpp.o.provides: Base/CMakeFiles/base.dir/test_base.cpp.o.requires
	$(MAKE) -f Base/CMakeFiles/base.dir/build.make Base/CMakeFiles/base.dir/test_base.cpp.o.provides.build
.PHONY : Base/CMakeFiles/base.dir/test_base.cpp.o.provides

Base/CMakeFiles/base.dir/test_base.cpp.o.provides.build: Base/CMakeFiles/base.dir/test_base.cpp.o


# Object files for target base
base_OBJECTS = \
"CMakeFiles/base.dir/BinaryTree.cpp.o" \
"CMakeFiles/base.dir/BinaryTreeProblem.cpp.o" \
"CMakeFiles/base.dir/LinkList.cpp.o" \
"CMakeFiles/base.dir/LinkListProblem.cpp.o" \
"CMakeFiles/base.dir/UnionFind.cpp.o" \
"CMakeFiles/base.dir/IntervalTree.cpp.o" \
"CMakeFiles/base.dir/HashSet.cpp.o" \
"CMakeFiles/base.dir/BFS.cpp.o" \
"CMakeFiles/base.dir/Graph.cpp.o" \
"CMakeFiles/base.dir/Trie.cpp.o" \
"CMakeFiles/base.dir/test_base.cpp.o"

# External object files for target base
base_EXTERNAL_OBJECTS =

Base/base: Base/CMakeFiles/base.dir/BinaryTree.cpp.o
Base/base: Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o
Base/base: Base/CMakeFiles/base.dir/LinkList.cpp.o
Base/base: Base/CMakeFiles/base.dir/LinkListProblem.cpp.o
Base/base: Base/CMakeFiles/base.dir/UnionFind.cpp.o
Base/base: Base/CMakeFiles/base.dir/IntervalTree.cpp.o
Base/base: Base/CMakeFiles/base.dir/HashSet.cpp.o
Base/base: Base/CMakeFiles/base.dir/BFS.cpp.o
Base/base: Base/CMakeFiles/base.dir/Graph.cpp.o
Base/base: Base/CMakeFiles/base.dir/Trie.cpp.o
Base/base: Base/CMakeFiles/base.dir/test_base.cpp.o
Base/base: Base/CMakeFiles/base.dir/build.make
Base/base: Base/CMakeFiles/base.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ning/Project/Algorithm/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable base"
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/base.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Base/CMakeFiles/base.dir/build: Base/base

.PHONY : Base/CMakeFiles/base.dir/build

Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/BinaryTree.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/BinaryTreeProblem.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/LinkList.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/LinkListProblem.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/UnionFind.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/IntervalTree.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/HashSet.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/BFS.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/Graph.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/Trie.cpp.o.requires
Base/CMakeFiles/base.dir/requires: Base/CMakeFiles/base.dir/test_base.cpp.o.requires

.PHONY : Base/CMakeFiles/base.dir/requires

Base/CMakeFiles/base.dir/clean:
	cd /Users/ning/Project/Algorithm/cmake-build-debug/Base && $(CMAKE_COMMAND) -P CMakeFiles/base.dir/cmake_clean.cmake
.PHONY : Base/CMakeFiles/base.dir/clean

Base/CMakeFiles/base.dir/depend:
	cd /Users/ning/Project/Algorithm/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ning/Project/Algorithm /Users/ning/Project/Algorithm/Base /Users/ning/Project/Algorithm/cmake-build-debug /Users/ning/Project/Algorithm/cmake-build-debug/Base /Users/ning/Project/Algorithm/cmake-build-debug/Base/CMakeFiles/base.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Base/CMakeFiles/base.dir/depend

