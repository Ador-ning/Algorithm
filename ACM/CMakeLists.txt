cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)
set(ACM_SRC
		Stack_Queue.cpp
		Tree.cpp
		UVa572.cpp
		11.1.cpp
		UVa506.cpp
		UVa816.cpp
		UVa1572.cpp
		UVa1599.cpp
		UVa12171.cpp
		UVa10305.cpp
		UVa10129.cpp
		UVa10562.cpp)

add_executable(acm ${ACM_SRC})