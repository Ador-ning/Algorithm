cmake_minimum_required(VERSION 3.1)

project(Algorithm)

set(CMAKE_CXX_STANDARD 17)

set(BASE_CLASS
		Ptr.h Ptr.cpp String.cpp String.h)

add_executable(class ${BASE_CLASS})