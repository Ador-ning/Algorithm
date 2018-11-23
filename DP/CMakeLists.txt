cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DP
		DynamicProgramming.cpp
		Fibonacci.cpp)

add_executable(dp ${SRC_DP})