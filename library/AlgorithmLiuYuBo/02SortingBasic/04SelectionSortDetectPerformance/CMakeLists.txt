cmake_minimum_required(VERSION 3.5)
project(03_Selection_Sort_Detect_Performance)

set(CMAKE_CXX_STANDARD 20)    # 不建议 "${CMAKE_CXX_FLAGS} -std=c++2a"
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(File main.cxx SortTestHelper.hxx)
add_executable(03_Selection_Sort_Detect_Performance ${File})