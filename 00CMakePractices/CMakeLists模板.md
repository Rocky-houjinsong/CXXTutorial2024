

1. 创建 可执行文件
2. 配置文件 --- CXX读取CMake变量 
3. 验证: 构建`CMake ..` 是否成功
4. 验证: C++启用的版本 
5. 验证: 控制台乱码解决





```cmake
cmake_minimum_required(VERSION 3.1...3.28) 								#版本范围

#[[编译链接 选项设置  -- project命令之前]]
set(CMAKE_CXX_STANDARD 17)		# 启用C++语言标准 17标准 (固定受限的枚举类型 通过 _cplusplus 宏定义查看)
set(CMAKE_CXX_EXTENSIONS OFF)  # 只启用ISO C++标准的编译器标志，而不使用特定编译器的扩展
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # ON时，如果指定的C++标准不可用，CMake将停止配置并出现错误，OFF时，如果标准不可用，可以降级处理

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")  # 指定编译类型 Debug Release RelWithDebInfo MinSizeRel
endif()   

if(UNIX OR APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -std=c++17")   #类Unix系统CMake无跨平台命令 触发 依赖版本
endif()
```



# 功能模块

----

### 内置数据 打印

```cmake
include(CMakePrintHelpers)     
cmake_print_variables(CMAKE_CXX_STANDARD)   # cmake .. 生成后 二次编辑 ,可使用cmake .  , 前提是借助 cmakecache.txt文件进行辅助构建生成 , 
cmake_print_variables(PROJECT_BINARY_DIR)     # build 所在目录  代表的 是 构建目录,也就是 cmake 指令 所在的目录 
cmake_print_variables(PROJECT_VERSION_MAJOR)     # 走 CMAKe 内置变量打印 版本信息 
cmake_print_variables(PROJECT_VERSION_MINOR) 
cmake_print_variables(CMAKE_VERSION) 
```



### 配置文件 

#### 1.Cmake 构建

> 将输入文件复制为输出文件，并把其中的`变量引用`替换为CMakeLists.txt中定义的变量，如果变量未定义，则替换为`空串`。输入文件中的变量引用方式为**@@变量名@@**或者**${变量名}**。
>
> 输入文件默认路径为`CMakeLists.txt`所在的路径，输出文件的路径默认为`cmake生成文件`所在的路径。

```cmake

set(STR_TEST "Hello This is variable from CMakeLists.txt")   # CMake 声明变量, 供配置文件使用

													#[CMake 反向读取CXX变量 可以吗? 如何实现 ?]
													#[语法 configure_file(<inputfile> <outputfile>) ]
configure_file(TutorialConfig.h.in CMakeTutorialConfig.h) #[ 一般是 .in 转化为 .h 文件源文件 目的: CXX 单向 读取CMake变量]

add_executable(CMakeTutorial tutorial.cxx)

#[h文件能导入的前提: 显式导入是手动设置相对路径 借助CMake导入需 导入路径 --> target_include_directories ]
#[该h文件在通过 configure_file编译出来,  路径在哪?  在 构建路径中(build 命令的参数路径)  "${PROJECT_BINARY_DIR}" ]
target_include_directories(CMakeTutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )
```



#### 2.h.in文件 配置

> 用==宏定义的方式==对变量进行定义

```ini
// 两种不同的 编写方式 
// 格式  配置文件变量名    CMakeLists.txt中文件变量名 

#define CMakeTutorialStep1_VERSION_MAJOR ${CMakeTutorialStep1_VERSION_MAJOR}
#define CMakeTutorialStep1_VERSION_MINOR @CMakeTutorialStep1_VERSION_MINOR@

#define STR_TEST  "${STR_TEST}"    //引入 CMakeLists中声明 设置的变量  但这里 类似宏定义,  需要 手动添加 双引号
//上述定义中@Tutorial_VERSION_MAJOR@、${Tutorial_VERSION_MINOR}、@STR_VAR@在输出文件中会被替换为CMakeLists.txt中定义的对应变量值。


```

#### 3.cxx文件读取

导入头文件,  使用头文件中的变量

## 库生成
