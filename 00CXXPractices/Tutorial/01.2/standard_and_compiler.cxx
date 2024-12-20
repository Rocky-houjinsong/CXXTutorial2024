#include <iostream>

using namespace std;

int main()
{
    std::cout << "Current C++ Stander: " << __cplusplus << std::endl;  //语言标准

    #if defined (__clang__) || defined (__llvm__)                       //通过检测宏常量判断编译器类型
        std::cout << "Current C++ Compiler :Clang" << std::endl;         //Clang编译器 
    #elif defined (__GUNC__) || defined (__GUNG__)
        std::cout << "Current C++ Compiler :GCC" << std::endl;  //GCC编译器
    #elif defined (_MSC_VER)
        std::cout << "Current C++ Compiler :MSVC" << std::endl;   //MSVC编译器
    #else 
        std::cout << "Current C++ Compiler :Others" << std::endl;
    #endif


    return 0;
}