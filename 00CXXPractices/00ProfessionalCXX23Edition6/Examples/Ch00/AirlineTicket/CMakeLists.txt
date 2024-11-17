cmake_minimum_required(VERSION 3.30...3.31 )


set(CMAKE_CXX_STANDARD 23)        
set(CMAKE_CXX_EXTENSIONS OFF)     
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)   
set(CMAKE_CXX_SCAN_FOR_MODULES ON)



#  knowledge: 跨平台 C/C++ 动态库 的符号隐藏  
# 安全: 去掉 不必要符号提高 逆向破解难度 
# 压缩空间: 符号实际上放在dll/so/ lib 中, 去掉 多余符号 缩减动态文件大小 
# 性能: 符号隐藏 意味着不会参与到  动态链接过程中,  编译器 有更大的 有优化空间 
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)

# Module 功能 必备命令行参数 
if(UNIX OR APPLE)
  # https://clang.llvm.org/docs/Modules.html
  add_compile_options(-fmodules)   # 启用模块功能
  #add_compile_options(-stdlib=libc++)
  add_compile_options(-fbuiltin-module-map)  # 加载Clang内置模块映射文件  -fmodule-map-file=<resource dir>/include/module.modulemap
  add_compile_options(-fimplicit-module-maps)  # 启用隐式搜索名为module.modulemap和 类似的模块映射文件
  #add_compile_options(-fmodules-ignore-macro=macroname)  # 指示模块在选择适当的模块变体时忽略指定的宏。对于在命令行上定义的不影响模块构建方式的宏，请使用此选项，以改善已编译模块文件的共享
  #add_compile_options(-fmodules-decluse)  # 启用模块声明检查use    这个不要启用,会报错
  add_definitions(-Wall)
endif()


# Options: 若CMake为 实验版本时 特殊处理
if(CMAKE_VERSION VERSION_LESS "3.28.0")
  if(CMAKE_VERSION VERSION_LESS "3.27.0")
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")
  else()
    set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "aa1f7df0-828a-4fcd-9afc-2dc80491aca7")
  endif()
  set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
else()
  cmake_policy(VERSION 3.28)
endif()






set(PREBUILT_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()


project(
 Ticket
  VERSION 1.0.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)


find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
  message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
endif()

#find_package(LLVM REQUIRED CONFIG)






add_executable(Ticket)
target_sources(Ticket
    PUBLIC
    AirlineTicketTest.cpp AirlineTicket.cpp
)
target_sources(Ticket
  PUBLIC
    FILE_SET all_my_modules TYPE CXX_MODULES FILES
    AirlineTicket.cppm#
)


include(CMakePrintHelpers)     # 内置的模组 CMakePrintHelpoers
cmake_print_variables(CMAKE_CXX_FLAGS)
