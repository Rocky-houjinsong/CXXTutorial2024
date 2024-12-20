cmake_minimum_required(VERSION 3.29...3.31 )


set(CMAKE_CXX_STANDARD 23)        
set(CMAKE_CXX_EXTENSIONS OFF)     
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)   
#set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
#set(CMAKE_VERBOSE_MAKEFILE ON)











#set(PREBUILT_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()


project(
  References
  VERSION 1.0.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目 - Demo程序 : 注释, 模块导入, 预处理命令, main函数,  输出输出流"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)




find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
  message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
endif()




add_executable(References 04_ConstReferenceParameters.cxx)



