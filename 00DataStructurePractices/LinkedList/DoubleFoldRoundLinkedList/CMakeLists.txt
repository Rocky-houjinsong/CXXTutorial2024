cmake_minimum_required(VERSION 3.1...3.28)

#[[启用编译 链接 相关 设置, 建议 设置在 project命令之前]]
set(CMAKE_CXX_STANDARD 20)   
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -std=c++17")
endif()

project(
  DCLinkTest
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



include(CMakePrintHelpers)     
cmake_print_variables(CMAKE_CXX_FLAGS)  # CXX编译器选项
cmake_print_variables(CMAKE_BUILD_TYPE) # 构建类型
cmake_print_variables(CMAKE_CXX_COMPILER) # CXX编译器
cmake_print_variables(CMAKE_TOOLCHAIN_FILE)  # 交叉编译工具链
cmake_print_variables(CMAKE_SYSTEM_NAME) # 目标系统名称
cmake_print_variables(CMAKE_INSTALL_RPATH) # 运行时动态链接库搜索路径
cmake_print_variables(BUILD_SHARED_LIBS) # 是否构建共享库
cmake_print_variables(CMAKE_VERBOSE_MAKEFILE)  # 生成Makefile时是否显示详细信息
cmake_print_variables(CMAKE_MODULE_PATH) # CMake模块路径
cmake_print_variables(CMAKE_INSTALL_PREFIX) # 安装目录
cmake_print_variables(CMAKE_PREFIX_PATH) # 第三方库安装路径

add_executable(DCLinkTest dclinkTest.cxx )

















