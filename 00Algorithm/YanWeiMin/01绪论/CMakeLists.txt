cmake_minimum_required(VERSION 3.10...3.30)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_COMPILER /usr/local/opt/llvm/bin/clang++)  

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")   	
	message(STATUS "No build type selected , default to RelWithDebInfo")
endif()


project(Introduction 
	VERSION 1.0.0
	DESCRIPTION "严蔚敏老师的绪论"
	LANGUAGES CXX C )

add_executable(Introduction scanf.cxx Status.hxx StructPointer.cxx VariadicFunction.cxx)

		

