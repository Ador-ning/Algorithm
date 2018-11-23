cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Campus)        #   the problem from Campus Interview Summarys in NiuKe
add_subdirectory(Leetcode)      #   the problem from Leetcode
add_subdirectory(Base)          #
add_subdirectory(Array)
add_subdirectory(String)

set(SRC_MAIN main.cpp)

# the project main
add_executable(main ${SRC_MAIN})