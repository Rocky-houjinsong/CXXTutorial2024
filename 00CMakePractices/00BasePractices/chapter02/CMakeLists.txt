# Top-level CMakeLists file for the Chapter 2 example content.
cmake_minimum_required(VERSION 3.21)

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


# 设置安装的位置前缀。默认在Unix-like是/usr/local, 在Windows是C:\Program Files。注意！这个设置必须在顶层的CMakeLists.txt当中指定！
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")

project(
    "CMake Best Practices Chapter 2"
    VERSION 1.0
    DESCRIPTION "A simple C++ project to demonstrate basic CMake usage"
    LANGUAGES CXX
)

# Option to exclude driver application from build.
set(CHAPTER2_BUILD_DRIVER_APPLICATION
    TRUE
    CACHE BOOL "Whether to include driver application in build. Default: True"
)
# Hide this option from GUI's by default.
mark_as_advanced(CHAPTER2_BUILD_DRIVER_APPLICATION)

# MSVC requires these two flags to be set in order to link driver executable
# against shared library.
# The topic is about symbol visibility will be further discussed in Chapter 3.
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  message(VERBOSE "Windows environment detected, overriding default symbol visibility to `visible` instead of `hidden`")
  # 编译动态库。注意在Windows平台需要将WINDOWS_EXPORT_ALL_SYMBOLS设置为ON（默认为OFF)，以设置符号可见性。
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()


add_subdirectory(component_interface)
add_subdirectory(component1)
add_subdirectory(component2)

# Include driver_app subdirectory if CHAPTER2_BUILD_DRIVER_APPLICATION flag is
# enabled.
if(CHAPTER2_BUILD_DRIVER_APPLICATION)
    add_subdirectory(driver_app)
endif()