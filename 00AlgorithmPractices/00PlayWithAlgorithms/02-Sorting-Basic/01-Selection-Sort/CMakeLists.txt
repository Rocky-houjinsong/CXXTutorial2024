cmake_minimum_required(VERSION 3.5)
project(SelectionSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(Files main.cxx)
add_executable(SelectionSort ${Files})