#                 [[顶级CMakeList.txt文件]]
# 该命令为 开头第一个命令,必须在 project()之前  建立版本和策略设置非常重要 
cmake_minimum_required(VERSION 3.5...3.20)

#                 [[启用编译 链接 相关 设置, 建议 设置在 project命令之前]]
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "No Build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()


project(SelectionSort)
set(Files main.cxx)
add_executable(SelectionSort ${Files})