cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DP
		problem.h
		BackTracing.cpp # 回溯算法
		DynamicProgramming.cpp
		Fibonacci.cpp
		test_dp.cpp)

add_executable(dp ${SRC_DP})