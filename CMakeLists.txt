cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Campus)        #   the problem from Campus Interview Summarys in NiuKe
add_subdirectory(Leetcode)      #   the problem from Leetcode
add_subdirectory(Base)          # Base data structure
add_subdirectory(Array)         # Array problem , sort types implement
add_subdirectory(String)        # String problem
add_subdirectory(DP)            # Dynamic Programming problem

set(SRC_MAIN main.cpp Base.h)

# the project main
add_executable(main ${SRC_MAIN})