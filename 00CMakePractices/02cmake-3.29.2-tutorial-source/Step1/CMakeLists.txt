cmake_minimum_required(VERSION 3.1...3.30)

#                               [[编译链接 选项设置 ]]
# 启用C++语言标准 17标准 (固定受限的枚举类型 通过 _cplusplus 宏定义查看)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
# ON时，如果指定的C++标准不可用，CMake将停止配置并出现错误，OFF时，如果标准不可用，可以降级处理
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)   #Clang
#set(CMAKE_CXX_COMPILER /usr/bin/clang++)   # AppleClang


# 指定编译类型 Debug Release RelWithDebInfo MinSizeRel
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()       

set(STR_TEST "Hello This is variable from CMakeLists.txt")

project(
  CMakeTutorialStep1
  VERSION 2.3.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)

#                                 [[构建链接 打印输出]]
#  方法一  直接打印 
message(STATUS "Hello World from cmake!")


# 方法二 CMakePrintHelpers 打印 
include(CMakePrintHelpers)     
cmake_print_variables(CMAKE_CXX_STANDARD)                                    # cmake .. 生成后 二次编辑 ,可使用cmake .  , 前提是借助 cmakecache.txt文件进行辅助构建生成 , 
cmake_print_variables(PROJECT_BINARY_DIR)     # build 所在目录  代表的 是 构建目录,也就是 cmake 指令 所在的目录 
cmake_print_variables(PROJECT_VERSION_MAJOR)     # 走 CMAKe 内置变量打印 版本信息 
cmake_print_variables(PROJECT_VERSION_MINOR) 
cmake_print_variables(CMAKE_VERSION) 

message(STATUS  "CXX Compiler is ${CMAKE_CXX_COMPILER_ID} ")


#[[ 配置文件  ---  将 输入文件 读取并  转化为 输出 文件  ,一般 是 .in 转化为 .h 文件 ,便于 配置 , 源文件方便 引入  

    问题: 输出文件 .h 的路劲 存在  构建路径中 ,也就是 此处的 build 文件路径中  和  顶级根CMakeLists.txt不在同一路径下,需手动添加 导入该路径 

    问: 如何验证 该语句执行正确 ?  message 获取变量值, 查看构建路径 是否有 输出文件,且输出文件中的值 就是 特定的

    配置文件  借助转化成的 头文件 引入 可被 源文件读取, 反过来可以吗???    
]]
configure_file(TutorialConfig.h.in CMakeTutorialConfig.h)




# TODO 3: Add an executable called Tutorial to the project
# Hint: Be sure to specify the source file as tutorial.cxx

#[[ 为 项目 添加一个 叫做 Tutorial.cxx 文件
    如果有多个 源文件(.cxx,cpp等格式)的文件需要添加 , 手动方式的话, 以 空格 或 分隔符; 进行 隔开 
    自动的 话 , 以 一个 变量 或者 文件搜索的方式 获取特定格式的 文件,然后 借助变量进行 赋值 
    cxx 格式后缀是 Linux平台的, CPP文件是Windows平台的, 但都可以识别和使用 
]]
add_executable(CMakeTutorial tutorial.cxx)
# TODO 9: Use target_include_directories to include ${PROJECT_BINARY_DIR}

#[[ 将 设计到的 ,被生成的 头文件   添加 进来 

  PUBLIC PRIVATE  INNER 三者  不同的 作用 
]]
# 此处 要引入的 目标是  TutorialConfig.h  所在路径 为构建路径    "${PROJECT_BINARY_DIR}"
target_include_directories(CMakeTutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )