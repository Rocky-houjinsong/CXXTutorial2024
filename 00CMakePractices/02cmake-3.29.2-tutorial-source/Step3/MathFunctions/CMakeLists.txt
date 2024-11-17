add_library(MathFunctions MathFunctions.cxx)    # 默认 类库创建是 静态库, 还有 动态库  以及 接口库的选项 

# TODO 1: State that anybody linking to MathFunctions needs to include the
# current source directory, while MathFunctions itself doesn't.
# Hint: Use target_include_directories with the INTERFACE keyword
target_include_directories(MathFunctions INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")


#        [[info:public private interface 区别]]

# PUBLIC 本目标需要, 依赖这个目标的其他目标也需要 
# INTERFACE 本目标不需要, 依赖这个目标的其他目标需要 
# PRIFVATE  本目标需要, 依赖这个目标的其他目标不需要

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
  	target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # library that just does sqrt
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  # TODO 6: Link SqrtLibrary to tutorial_compiler_flags
  target_link_libraries(SqrtLibrary PUBLIC  tutorial_compiler_flags)
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary )

endif()

message(STATUS "LibMathFuction ------- ${CMAKE_CUTTENT_SOURCE_DIR} ")
# TODO 7: Link MathFunctions to tutorial_compiler_flags
target_link_libraries(MathFunctions PUBLIC tutorial_compiler_flags)



#[[ interrobang:  MathFunctions 中是否引用两次 tutorial_compiler_flags 库呢? ]]