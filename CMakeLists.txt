#[[顶级CMakeList.txt文件]]
#[[ 该命令为 开头第一个命令,必须在 project()之前  建立版本和策略设置非常重要 ]]
cmake_minimum_required(VERSION 3.1...3.28)

#[[启用编译 链接 相关 设置, 建议 设置在 project命令之前]]
set(CMAKE_CXX_STANDARD 20)    # 不建议 "${CMAKE_CXX_FLAGS} -std=c++2a"
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -std=c++17")
endif()

#[[问题:  如何解决 中文乱码问题?  ]]


#[[定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言默认情况支持所有语言
 项目名称 存储到 CMAKE_PROJECT_NAME 中 
 项目版本信息 存储到  CMAKE_PROJECT_VERSION 中 
 项目描述 存储到 CMAKE_PROJECT_DESCRIPTION 中]]
project(
  ModernCMakeCXX20
  VERSION 1.0.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)

  find_program(CCACHE_PROGRAM ccache)
  if (CCACHE_PROGRAM)
	  message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
	  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
	  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
  endif()


# testing settings
#include(cmake/Testing.cmake)

# adjust or override some CMake defaults
include(cmake/OverrideCMakeDefaults.cmake)

# default compiler options and warnings
include(cmake/DefaultCompilerOptions.cmake)
include(cmake/DefaultCompilerWarnings.cmake)

# static analyzers
include(cmake/StaticAnalyzers.cmake)

# sanitizers
include(cmake/Sanitizers.cmake)



#[[打印输出相关变量]]
include(CMakePrintHelpers)     # 内置的模组 CMakePrintHelpoers
cmake_print_variables(CMAKE_CXX_FLAGS)
#find_package(fmt CONFIG REQUIRED)
#add_subdirectory(src/example)
#add_subdirectory(src/show_info)


# 定义工程会生成一个可执行程序 如有多个可用空格或;间隔
add_executable(ModernCMakeCXX20 ./src/main.cxx )

















