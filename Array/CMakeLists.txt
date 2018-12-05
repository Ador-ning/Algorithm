cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(SRC_ARRAY
		sort.h
		sort.cpp
		problem.h
		problem.cpp
		RotatedArray.cpp
		SortedArray.cpp
		DupArrayNoEdit.cpp
		DuplicationInArray.cpp
		FindandSort.cpp
		test_array.cpp)

add_executable(array ${SRC_ARRAY})