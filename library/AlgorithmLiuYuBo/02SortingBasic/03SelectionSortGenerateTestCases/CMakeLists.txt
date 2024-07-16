cmake_minimum_required(VERSION 3.5)
project(03_Selection_Sort_Generate_Test_Cases)


set(CMAKE_CXX_STANDARD 20)    # 不建议 "${CMAKE_CXX_FLAGS} -std=c++2a"
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(Files main.cxx SortTestHelper.hxx)
add_executable(03_Selection_Sort_Generate_Test_Cases ${Files})