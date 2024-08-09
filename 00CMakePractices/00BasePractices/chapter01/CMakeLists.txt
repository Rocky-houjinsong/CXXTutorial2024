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
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)
# 指定编译类型 Debug Release RelWithDebInfo MinSizeRel
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

#[[定义工程名称，并可指定工程的版本、工程描述、web主页地址、支持的语言默认情况支持所有语言
 项目名称 存储到 CMAKE_PROJECT_NAME 中 
 项目版本信息 存储到  CMAKE_PROJECT_VERSION 中 
 项目描述 存储到 CMAKE_PROJECT_DESCRIPTION 中]]
project(
    chapter_1
    VERSION 1.0
    DESCRIPTION
        "Examples for chapter 1 of the CMake Best Practices book"
    LANGUAGES CXX
)

# 添加子目录 add_subdirectory()
add_subdirectory(simple_executable)
add_subdirectory(policy_example)

#                    [[内置模组系列]]
include(CMakePrintHelpers)       # 打印输出相关变量 CMakePrintHelpoers
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

include(CMakeDependentOption)     #内置模组 创建一个依赖于另一个选项的选项
# 创建一个配置选项。该选项可以在CMake生成的配置界面中显示，并且用户可以选择其值,  提示内容  默认值
option(CHAPTER1_PRINT_LANGUAGE_EXAMPLES "Print examples for each language" OFF)
# 创建 一个选项(CHAPTER1_PRINT_HELLO_WORLD) 仅当 选项(CHAPTER1_PRINT_LANGUAGE_EXAMPLES) 为 ON时, 显示 且 可用, 否则  禁用或隐藏
cmake_dependent_option(CHAPTER1_PRINT_HELLO_WORLD "Print a nice greeting from chapter1" ON CHAPTER1_PRINT_LANGUAGE_EXAMPLES ON)
#标记 当前变量  为 高级变量 基本无法由终端用户直接维护, 而是CMakeLists文件其他部分/模块维护 Aim: 组织管理 工程的配置选项,  提高可维护性
mark_as_advanced(CHAPTER1_PRINT_LANGUAGE_EXAMPLES)  

if(CHAPTER1_PRINT_LANGUAGE_EXAMPLES)
    if(CHAPTER1_PRINT_HELLO_WORLD)
        message(STATUS "Chapter1: welcome to chapter 1!")
    endif()
    #examples for list operations
    set(MYLIST abc def ghi)   # set 设置变量, 三个字符串元素,  option 设置选项            
    message(STATUS "Chapter1: MYLIST is: ${MYLIST}")
    set(MYLIST "abc;def;ghi") #TODO: 前后两个 set有何不同? 
    message(STATUS "Chapter1: MYLIST is: ${MYLIST}")
    list(APPEND MYLIST "xyz") # 在 变量(MYLST) 追加 元素(xyz) ,变量不存在则 新建变量并添加元素, 否则 在末尾后添加该元素
    message(STATUS "Chapter1: MYLIST is: ${MYLIST}")

    list(FIND MYLIST def ABC_INDEX)   #在列表变量(MYLIST) 中寻找特定元素(def),若找到,索引存储到变量(ABC_INDEX) 中 
    list(GET MYLIST ${ABC_INDEX} ABC) #在列表变量(MYLIST)中 寻找特定索引的元素 赋值给变量(ABC)
    message(STATUS "Chapter1: Index of 'def' in MYLIST is ${ABC_INDEX} the value at the index is '${ABC}'")

    # set(<variable> <value> CACHE <type> "docstring")
    # 定义并初始化变量(ch1_MYVAR) 值(foo) 类型(String) 描述信息 且 可缓存, Aim: 可在配置过程中被用户修改, 定制化配置工程中使用
    set(ch1_MYVAR foo CACHE STRING "Variable foo that configures bar")

    # 设置默认路径(CMakeLists.txt)目录的属性 名(CHAPTER1_PROPERTY), 值(Hello from chapter 1)
    set_property(DIRECTORY PROPERTY CHAPTER1_PROPERTY "Hello from chapter 1")
    # 获取 指定目录属性的值,存储到变量(CH1_PROPERTY_VARIABLE)中
    get_property(CH1_PROPERTY_VARIABLE DIRECTORY PROPERTY CHAPTER1_PROPERTY)
    message(STATUS "Chapter1: Property value for CHAPTER1_PROPERTy is '${CH1_PROPERTY_VARIABLE}'")

   

    #                                   [[循环 示例]]
    set(MYVAR 0)
    while(MYVAR LESS "5")           # 循环 步进
        message(STATUS "Chapter1: MYVAR is '${MYVAR}'")
        math(EXPR MYVAR "${MYVAR}+1")   #效果等同MYVAR自增+1 , EVPR是math命令的子命令 执行表达式 结果存储到变量中
    endwhile() 

    foreach(ITEM IN LISTS MYLIST)    # 迭代器 foreach
        message(STATUS "Chapter1: ITEM from MYLIST is '${ITEM}'")
    endforeach() 

    foreach(ITEM RANGE 0 5 1)  # 创建循环 [0, 5] 步进1 
        message(STATUS "Chapter1: ITEM from RANGE is '${ITEM}'")
    endforeach() 

    #                               [[声明函数 调用函数]]
    # 允许 声明带有默认参数值的函数
    function(foo ARG1 ARG2 ARG3="default_value3") 
        message(STATUS "Chapter1: foo called with '${ARG1}'")
        message(STATUS "Chapter1: foo called with '${ARG2}'")
        message(STATUS "Chapter1: foo called with '${ARG3}'")
    endfunction() 

    # invoke foo with parameter bar 
    foo("debug" "release") 
    foo("debug" "release" "minRelease") 
endif()


#                                                   [[笔记]]

#[[

常用循环三种写法 list, range, 自增
set设置变量, option 设置配置选项 
编译 配置等最好在project之前设置 

添加 子目录 add_subdirectory()
如何启动 基于依赖的依赖 ,链式依赖/层级依赖的配置选项 

  ]]