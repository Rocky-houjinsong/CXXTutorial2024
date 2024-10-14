cmake_minimum_required(VERSION 3.5...3.30) # set minimun version 

#                cxx language option setting 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

#               cxx build compiler option setting 
# 使用 llvm中 clang编译器 ; CIID中可 检测安装 该编译器,Mac本地开发已安装
set(CMAKE_CXX_COMPILER  /usr/local/opt/llvm/bin/clang++) 

if  (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No Build type selected , default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

#                   project base information setting 
project(
    PlayerMove
    VERSION 1.0.1
    DESCRIPTION "CXX在控制终端 的 二维点阵中 模拟 上下左右移动"
    HOMEPAGE_URL "https://github.com"
    LANGUAGES CXX
)



#                  file层面组合: 定义与实现引用 - 头文件;  库 模块 

include_directories(include)
aux_source_directory(GameMap GameMap_SOURCE_FILES)  # 是否可以动态更新 ??  增减修改某文件, 该组合中是否 可 同步更新? 
aux_source_directory(Player Player_SOURCE_FILES)
aux_source_directory(Main Main_SOURCE_FILES)


add_library(GameMap SHARED ${GameMap_SOURCE_FILES})
add_library(Player SHARED ${Player_SOURCE_FILES})

target_link_libraries(Player GameMap)

add_executable(exec ${Main_SOURCE_FILES})
target_link_libraries(exec GameMap Player)

install(TARGETS exec GameMap Player RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin)






#         CMake  variable list  

set(STR_TEST "This is variable from CMakeList.txt")



#          cmake build  generate option output.  CMake 生成 构建两阶段 默认属性值打印 
include(CMakePrintHelpers)

message("=========== CMake option setting ===========")
cmake_print_variables(CMAKE_CXX_STANDARD) 
cmake_print_variables(CMAKE_VERSION)

message("========== Project option setting ===========")
cmake_print_variables(PROJECT_BINARY_DIR) #build所在目录 构建输出目录 
cmake_print_variables(PROJECT_VERSION_MAJOR)
cmake_print_variables(PROJECT_VERSION_MiNOR)