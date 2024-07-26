cmake_minimum_required(VERSION 3.10)

project(Tutorial VERSION 1.0)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


configure_file(TutorialConfig.h.in TutorialConfig.h)

add_subdirectory(MathFunctions)    # Use add_subdirectory() to add MathFunctions to this project

add_executable(Tutorial tutorial.cxx)


target_link_libraries (Tutorial PUBLIC MathFunctions)   # Use target_link_libraries to link the library to our executable



# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${PROJECT_SOURCE_DIR}
                           )
