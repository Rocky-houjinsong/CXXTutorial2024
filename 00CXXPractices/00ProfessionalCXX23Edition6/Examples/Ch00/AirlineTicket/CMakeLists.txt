cmake_minimum_required(VERSION 3.1...3.28)

#[[启用编译 链接 相关 设置, 建议 设置在 project命令之前]]
set(CMAKE_CXX_STANDARD 20)    # 不建议 "${CMAKE_CXX_FLAGS} -std=c++2a"
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)

set(PREBUILT_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -std=c++17 -fexec-charset=GBK")
  add_compile_options(-fmodules)
  add_compile_options(-stdlib=libc++)
  add_compile_options(-fbuiltin-module-map)
  add_compile_options(-fimplicit-module-maps)
  message(STATUS " -fPIC -Wall -std=c++17 -fexec-charset=GBK")
endif()

project(
 Ticket
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



add_executable(Ticket)
target_sources(Ticket
    PUBLIC
    AirlineTicketTest.cpp
)
target_sources(Ticket
  PUBLIC
    FILE_SET all_my_modules TYPE CXX_MODULES FILES
    AirlineTicket.cppm
)


include(CMakePrintHelpers)     # 内置的模组 CMakePrintHelpoers
cmake_print_variables(CMAKE_CXX_FLAGS)
