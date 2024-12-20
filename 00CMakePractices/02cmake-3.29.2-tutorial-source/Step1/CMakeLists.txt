cmake_minimum_required(VERSION 3.15...3.30)

#                               [[编译链接 选项设置 ]]
set(CMAKE_CXX_STANDARD 20)           # 启用C++语言标准 17标准 (固定受限的枚举类型 通过 _cplusplus 宏定义查看) 
set(CMAKE_CXX_EXTENSIONS ON)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # info:ON时，如果指定的C++标准不可用，CMake将停止配置并出现错误，OFF时，如果标准不可用，可以降级处理
set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)   #Clang
#set(CMAKE_CXX_COMPILER /usr/bin/clang++)   # AppleClang


if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to RelWithDebInfo")
    set(CMAKE_BUILD_TYPE "RelWithDebInfo")          # 指定编译类型 Debug Release RelWithDebInfo MinSizeRel
endif()       

#                             [[变量  选项  ]]
set(STR_TEST "Hello This is variable from CMakeLists.txt")    # CMak中设定  变量, 在配置文件 到 CXX头文件中 变化   
message(STATUS  "STR_TEST : ${STR_TEST}")   #验证: CMake中字符变量 是不带 双引号的, 在配置文件 .h.in中是 需要手动添加双引号的   info: 访问变量的 通用方法  "${Variable}"   在 构建阶段查看 该变量的值



project(
  CMakeTutorialStep1
  VERSION 2.3.12
  DESCRIPTION "项目描述:基于CMake3构建工具的 CXX20 项目  创建 可执行程序/类库"
  HOMEPAGE_URL "https://github.com/Rocky-houjinsong/CMakeTutorialCXX20"
  LANGUAGES CXX)

#                                 [[构建链接 打印输出]]
message(STATUS "Hello World from cmake!")
message(STATUS "PROJECT_VERSION_MAJOR : ${PROJECT_VERSION_MAJOR}")  # 版本号 打印前,必须 初始化, Project命令中初始化有值
message(STATUS "CMakeTutorialStep1_VERSION_MAJOR : ${CMakeTutorialStep1_VERSION_MAJOR}")
message(STATUS  "CXX Compiler is ${CMAKE_CXX_COMPILER_ID} ")


include(CMakePrintHelpers)     
cmake_print_variables(CMAKE_CXX_STANDARD)     # cmake .. 生成后 二次编辑 ,可使用cmake .  , 前提是借助 cmakecache.txt文件进行辅助构建生成 , 
cmake_print_variables(PROJECT_BINARY_DIR)     #warning: build 所在目录  代表的 是 构建目录,也就是 cmake 指令 所在的目录 
cmake_print_variables(PROJECT_VERSION_MAJOR)     # 走 CMAKe 内置变量打印 版本信息 
cmake_print_variables(PROJECT_VERSION_MINOR) 
cmake_print_variables(CMAKE_VERSION) 

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")
endif()


#[[ info: 配置文件--> 将 输入文件 读取并  转化为 输出 文件  ,一般 是 .in 转化为 .h 文件 ,便于 配置 , 源文件方便 引入  
    warning: 输出文件 .h 的路径 存在  构建路径中 ,也就是 此处的 build 文件路径中  和  顶级根CMakeLists.txt不在同一路径下,需手动添加 导入该路径 
    
    initerrobang: 如何验证 该语句执行正确 ?  
    verification: 查看构建路径 是否存在对应的输出文件 ,且输出文件内容 有 CMake变量转换的,   ls 和 cat 命令
    
    interrobang: 配置文件  借助转化成的 头文件 引入 可被 源文件读取, 反过来可以吗???    
]]
# 输入文件  输出文件
configure_file(TutorialConfig.h.in CMakeTutorialConfig.h)




#[[ knowledge:   项目添加 可执行文件

    info: 如果有多个 源文件(.cxx,cpp等格式)的文件需要添加 , 手动方式的话, 以 空格 或 分隔符; 进行 隔开 
    info: 自动的 话 , 以 一个 变量 或者 文件搜索的方式 获取特定格式的 文件,然后 借助变量进行 赋值 
    cxx 格式后缀是 Linux平台的, CPP文件是Windows平台的, 但都可以识别和使用 
    info: 项目名是 项目名, 可执行程序名是可执行程序的名字,二者可以不一样,最终生成的 可执行程序名字 
    verification: 在此处修改 add_executable 中第一个参数, 同步修改相关的命令  最后 查看 生成的可执行程序名字
]]
add_executable(step1 tutorial.cxx)

#[[                 knowledge: 指定待引入的头文件路径 
    info:PUBLIC PRIVATE  INNER 三者  不同的 作用 
]]
# 此处 要引入的 目标是  TutorialConfig.h  所在路径 为构建路径    "${PROJECT_BINARY_DIR}"
# warning: 用 双引号 引起来,  若路径中有空格,不会 视为 切分的多个路径,而是视为 路径的一部分 避免找不到路径而报错
# 指定头文件的搜索路径 ??  可执行程序中 引用的头文件 路径在 构建路径build中, 但 相对于 此CMakeLists.txt是不同级,需手动指定搜索路径
#target 此处指 executable对象  ,含义是  这个对象的头文件搜索路径是 ? 
target_include_directories(step1 PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

#[[       knowledge

1. 基础必备命令 是哪三个?  
2. Mac中 手动设置编译器 为LLVM的Clang  
3. CMakePrintHelpers 内置打印输出帮助工具 
4. 配置文件 实现 读取 CMake变量 到 CXX源码文件中
5. 头文件引用 引用文件路径 


1. cmke_minimun_required, project, add_executable
2. set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/clang++)
3.  略
4. 01:{CMakeLists.txt 中 声明并初始化CMake变量  set语句}    
   02:{TutorialConfig.h.in 中  创建配置文件, 声明并引用 CMake变量}     
   03:{CMakeLists.txt 中 引入配置文件, 生成头文件  --> configure_file命令}  
  
   99: 本质上 还是 落实到 CXX实现文件 引入 HXX声明文件 ; 在 CXX中 引入并使用 类成员
5. target_include_directories()

]]

#[[  本项目 检索关键字 细节 

info: 语法细节, 注意点等,例如 set变量的使用 走"${VARIABLE}"  目的是 将 变量值中 空格视为整体的一部分,不做间隔符, 在 值为路径的场景中很有用 等
waring: 警告, 易错点 . 例如 配置文件中 define 和 cmakedefine 之间的异同点,  基于该点,明确使用场景
knowledge: 知识点整理,例如 教程之后的 技能点整理,列出掌握的点  并整理出答案
interrobang: 疑问点,例如 库引用 最初是是 引入库目录, 链接库, 指定库目路径 ,如何 优化,在链接库时自动带入 库所在路径呢?  往往是推动下一个 教程的 疑惑
verification: 验证. 对 语法细节,对 疑问点 提供 验证 

]]


#[[   项目运行  基础通用shell语句

cd build   --> 进入build目录  构建目录中
rm -rf *   ---> 重置构建编译环境
cmake ..  -->CMake构建阶段

cmake --build .  ---> CMake 编译生成阶段  
cmake --build . -j8  ---> CMake 编译生成阶段 并发 8现成编译
cmke --build . --verbose    --> CMake 编译生成阶段  输出更详细的构建信息

cmake -LAH   --> 查看构建生成时 所有的变量的值  -L 所有可用的变量, -A 构建系统的平台相关信息


分两种 是否携带入参 

setp1 

setp2  100   

]]


#[[      项目缺点 

1. 所有代码都写到一个文件, 扩展性差,可维护性差,如何 优化封装为 一个类库?  
2. 类库使用内置的, 如何使用自定义封装的类库 ? 
]]










