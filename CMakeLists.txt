cmake_minimum_required(VERSION 3.3)
project(icpc2006)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES icpc2006.cpp)
add_executable(icpc2006 ${SOURCE_FILES})