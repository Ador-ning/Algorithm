cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_STRING
		StringUtils.h
		StrinngsUtils.cpp
		problem.h
		KMP.cpp
		ReplaceBlank.cpp
		test_string.cpp)

add_executable(string ${SRC_STRING})