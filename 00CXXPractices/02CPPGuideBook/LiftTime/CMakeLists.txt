#                 [[顶级CMakeList.txt文件]]
# 该命令为 开头第一个命令,必须在 project()之前  建立版本和策略设置非常重要 
cmake_minimum_required(VERSION 3.21...3.30)

#                 [[启用编译 链接 相关 设置, 建议 设置在 project命令之前]]
# c++标准，如98 11 14 17 20
set(CMAKE_CXX_STANDARD 17)
# 只启用ISO C++标准的编译器标志，而不使用特定编译器的扩展
set(CMAKE_CXX_EXTENSIONS OFF)
# ON时，如果指定的C++标准不可用，CMake将停止配置并出现错误，OFF时，如果标准不可用，可以降级处理
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定编译类型 Debug Release RelWithDebInfo MinSizeRel
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


#[[定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言默认情况支持所有语言
 项目名称 存储到 CMAKE_PROJECT_NAME 中 
 项目版本信息 存储到  CMAKE_PROJECT_VERSION 中 
 项目描述 存储到 CMAKE_PROJECT_DESCRIPTION 中]]
 project(
    LiftTime01
    VERSION 1.0
    DESCRIPTION
        "Examples for LiftTime01 of the CMake Best Practices book"
    LANGUAGES CXX
)

add_executable(LiftTime01 main.cxx ClassTest.cxx)

include(CMakePrintHelpers)   
cmake_print_variables(CMAKE_CXX_STANDARD)                                    # cmake .. 生成后 二次编辑 ,可使用cmake .  , 前提是借助 cmakecache.txt文件进行辅助构建生成 , 
cmake_print_variables(PROJECT_BINARY_DIR)     # build 所在目录  代表的 是 构建目录,也就是 cmake 指令 所在的目录 
cmake_print_variables(PROJECT_VERSION_MAJOR)     # 走 CMAKe 内置变量打印 版本信息 
cmake_print_variables(PROJECT_VERSION_MINOR) 
cmake_print_variables(CMAKE_VERSION) 
