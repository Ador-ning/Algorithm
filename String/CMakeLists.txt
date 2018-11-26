cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_STRING
		ReplaceBlank.cpp
		StringUtils.h
		test_string.cpp)

add_executable(string ${SRC_STRING})