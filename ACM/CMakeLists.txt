cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)
set(ACM_SRC
		Stack_Queue.h
		Stack_Queue.cpp
		Tree.h
		Tree.cpp
		Graph.cpp
		Graph.h
		test_acm.cpp)

add_executable(acm ${ACM_SRC})