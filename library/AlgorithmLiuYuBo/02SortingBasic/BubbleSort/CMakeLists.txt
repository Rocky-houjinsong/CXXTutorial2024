cmake_minimum_required(VERSION 3.5)
project(Optional_01_Bubble_Sort)

set(CMAKE_CXX_STANDARD 20)    # 不建议 "${CMAKE_CXX_FLAGS} -std=c++2a"
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(files main.cxx SortTestHelper.hxx SelectionSort.hxx InsertionSort.hxx)
add_executable(Optional_01_Bubble_Sort ${files})