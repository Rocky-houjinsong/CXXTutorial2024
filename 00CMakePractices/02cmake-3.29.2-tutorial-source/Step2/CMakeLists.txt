cmake_minimum_required(VERSION 3.21...3.30)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()  

set(STR_TEST "Hello This is variable from CMakeLists.txt")          
message(STATUS  STR_TEST : "${STR_TEST}")  

option(USE_MYMATH "Use my Math ?" ON)          #warning  option/set 和 message 不可以在同一行 ,会报错                    
message(STATUS USE_MYMATH = "${USE_MYMATH}")   # 已构建修改选项值, 直接读取缓存,需清理缓存 才生效

project(
  CMakeTutorialStep2
  VERSION 2.3.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目: 链接一个库?? "
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)


include(CMakePrintHelpers)     
cmake_print_variables(CMAKE_CXX_STANDARD)     
cmake_print_variables(PROJECT_BINARY_DIR)     
cmake_print_variables(PROJECT_VERSION_MAJOR)     
cmake_print_variables(PROJECT_VERSION_MINOR) 
cmake_print_variables(CMAKE_VERSION) 



configure_file(TutorialConfig.h.in TutorialConfig.hxx)

if(USE_MYMATH)
  
add_subdirectory(MathFunctions)   #添加 子文件夹  存放 文件夹的名称 
list(APPEND EXTRA_LIBS MathFunctions)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")
endif()



add_executable(CMakeTutorialStep2 tutorial.cxx)

#CLI 等效  -lMathFunctions
#询问, 前后两个名字是 库名字 还是 目录名字? 
#在 库的 CMakeLists.txt中 声明库;  在 引用库的 CMakeLists.txt中 添加 库所在目录之后, 需将 可执行程序/库 和 待链接库 建立链接  
# 选项option - USE_MYMATH 为空, EXTRA_LIBS 为空, 走 空链接 等效 无链接
target_link_libraries (CMakeTutorialStep2 PUBLIC ${EXTRA_LIBS})   # Use target_link_libraries to link the library to our executable




target_include_directories(CMakeTutorialStep2 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${EXTRA_INCLUDES}"
                           )

message(STATUS Root CMakeLists.txt ---- "${PROJECT_SOURCE_DIR}")







#[[         knowledge:
    1. 打包并使用静态库 
    2. 可选项 使用  


    1. 01: { LibCMakeLists.txt中,   基于源文件 创建类库   add_library命令引入CXX源文件, 若需手动引入头文件 则 target_include_directories }
       02: { RootCMakeLists.txt中,  项目 引入 类库目录  add_subdirectory  }
       03: { RootCMakeLists.txt中,  项目 链接 类库  target_link_libraries }
       04: { RootCMakeListx.txt中,  项目 引入 类库头文件  基于声明和实现分离原则, 在项目中使用类库成员(函数,数据) 需指定 类库的头文件路径}

       99: 本质落实到CXX 引入HXX 

    2. 01: {CMakeLists.txt中,  声明 cmake变量}
       02: { .h.in中, cmakedefine 声明宏定义}
       03: {CMakeLists.txt中, configure_file 配置文件转换为头文件}

       99: CXX中借助 宏定义 使用 头文件 分支选择  




  cmake .. -DUST_MYMATH=ON    --> 构建阶段设置 选项值

]]


#[[    interrabang:

    1. 项目引用类库, 不仅要链接类库,还要 手动导入  类库的头文件,  可否优化成 , 当 链接类库的同时,自动将 类库的头文件路径 包含进项目呢? 

]]


