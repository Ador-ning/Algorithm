cmake_minimum_required(VERSION 3.1)
project(Algorithm)
set(CMAKE_CXX_STANDARD 17)

# the problem from Campus Interview Summarys in NiuKe
add_subdirectory(Campus)
# the problem from Leetcode
add_subdirectory(Leetcode)
# Base data structure
add_subdirectory(Base)
# Array problem , sort types implement
add_subdirectory(Array)
# String problem
add_subdirectory(String)
# Dynamic Programming problem
add_subdirectory(DP)
# 实现基本类
add_subdirectory(BaseClass)

# 基本实现
add_subdirectory(Recipes)



set(SRC_MAIN main.cpp
		Base.h Base.cpp
		BaseClass/String.h BaseClass/String.cpp
		BaseClass/Ptr.h BaseClass/Ptr.cpp
		poll_server.cpp
		poll_client.cpp)

# the project main
add_executable(main ${SRC_MAIN})