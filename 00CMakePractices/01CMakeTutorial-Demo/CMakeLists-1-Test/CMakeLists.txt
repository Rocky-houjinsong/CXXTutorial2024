# 1,设置工程名称，叫“Demo1”（在Linux下可以随便设置）
project( Demo1 )

# 2,设置 CMake 最低版本号，我电脑装的是3.5
cmake_minimum_required( VERSION 3.5 )

# 3,设定编译参数
set(CMAKE_CXX_STANDARD    11)  # 指定 C++ 版本
set(CMAKE_BUILD_TYPE "Release")  # 调试使用Debug，可以查看中间变量；发布使用Release，运行速度快

# 4，把当前文件夹下的源码列表（文件后缀匹配的那些文件）存到变量 SRCS 中
file( GLOB SRCS *.cxx *.cpp *.cc *.hxx *.hpp )

# 5，把源码编译成一个可执行文件，文件名为test01（可以随便取名），会保存在当前目录下
add_executable( test01 ${SRCS} )
