cmake_minimum_required(VERSION 3.28...3.30) 

set(CMAKE_CXX_STANDARD 23)        
set(CMAKE_CXX_EXTENSIONS OFF)     
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)   
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN TRUE)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(PREBUILT_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

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

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
  message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
endif()


project(Variables 
	VERSION 0.1.0 
	DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目 - 1.1.2 名称空间 : 名称空间的嵌套, 以及 别名问题"
	LANGUAGES CXX)


#add_executable(Variables 01_variables.cxx)    # 验证 未初始化的变量 会被赋予 一个 半随机的值, Bug来源
# add_executable(Variables 02_types.cxx)    # C++ 内置类型集合的初始化
add_executable(Variables 03_numeric_limits.cxx)    # C++ 数值类型极限
# add_executable(Variables 04_casting.cxx)    # C++ 显式类型转换

