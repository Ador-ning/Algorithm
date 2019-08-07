cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_BASE
		BinaryTree.h # Binary Tree
		BinaryTree.cpp
		BinaryTreeProblem.cpp
		LinkList.h  # Link list
		LinkList.cpp
		LinkListProblem.h
		LinkListProblem.cpp
		UnionFind.h     # Union and found
		UnionFind.cpp
		IntervalTree.h # interval tree
		IntervalTree.cpp
		HashSet.h # hash
		HashSet.cpp
		BFS.h   # BFS
		BFS.cpp
		UVa572.h     # Graph
		Graph.cpp
		Trie.h      # trie 前缀树
		Trie.cpp
		ComplexList.h
		BST.h   # Bianry search tree
		AVL.h   # AVL tree  --> have a bug
		Tree.h
		Queue.h
		Heap.h
		DFS.h
		test_base.cpp  # test_main
		)

add_executable(base ${SRC_BASE})