# CMakeLists file for the Chapter 2 - Component Interface
# 组件接口
# SPDX-License-Identifier: MIT

project(
    ch2_framework_component_interface
    VERSION 1.0
    DESCRIPTION "Chapter 2 component interface implementation"
    LANGUAGES CXX
)

# add_library  设置为 INTERFACE 即 接口库 (不含 实际的实现代码或 链接库文件  --- 设置路径 不设置包含的文件) 
# Aim: 用于 指定 编译器 链接器选项, 提供 包含路径 和 编译特性等信息 
# 其他目标 链接到接口库,  可访问 该接口库定义的 的选项 等特性 
add_library(ch2_framework_component_interface INTERFACE)
# 设置 类库的所引用的头文件路径 --- 只需要设置路径即可 ----------- 特性1 
target_include_directories(
  ch2_framework_component_interface INTERFACE include/
)
# 设置 启用C++17的编译特性 ----- 特性2 
target_compile_features(ch2_framework_component_interface INTERFACE cxx_std_11)

# Make specified target(s) installable. Separate them to components.
install(TARGETS ch2_framework_component_interface COMPONENT ch2.libraries)

# Install the headers
# 目录下的所有头文件安装到系统的include目录下，
# 并将其标记为ch2.libraries组件。在安装目标时，可以选择性地只安装ch2.libraries组件，而不安装其它组件的内容
install(
    DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
    COMPONENT ch2.libraries
    DESTINATION include
)
