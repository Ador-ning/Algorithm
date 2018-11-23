cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_BASE
		Base.h   # processing the input
		BinaryTree.h # Binary Tree
		BinaryTree.cpp
		Graph.h     # Graph
		Graph.cpp
		LinkList.h  # Link list
		LinkList.cpp
		ComplexList.h
		BST.h   # Bianry search tree
		AVL.h   # AVL tree  --> have a bug
		Tree.h
		Queue.h
		Heap.h
		DFS.h)

add_executable(base ${SRC_BASE})