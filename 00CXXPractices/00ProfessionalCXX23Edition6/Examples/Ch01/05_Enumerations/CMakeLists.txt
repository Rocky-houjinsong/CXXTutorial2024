cmake_minimum_required(VERSION 3.29...3.31 )


set(CMAKE_CXX_STANDARD 23)        
set(CMAKE_CXX_EXTENSIONS OFF)     
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)   
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
set(CMAKE_VERBOSE_MAKEFILE ON)

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









set(PREBUILT_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()


project(
 Enumerations
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




add_executable(Enumerations StronglyTypedEnums.cxx)



