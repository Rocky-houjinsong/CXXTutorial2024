#include <cmath>#include <iostream>#include <string>#include "CMakeTutorialConfig.h"          // 引入由配置文件生成的 头文件using namespace std;int main(int argc, char* argv[]){  if (argc < 2) {    std::cout << "Usage: " << argv[0] << " number" << std::endl;    std::cout << "__cplusplus: " << __cplusplus << std::endl;             //  该 宏定义 : C++语言标准    std::cout << "CMakeTutorial_VERSION_MAJOR: " << CMakeTutorialStep1_VERSION_MAJOR << std::endl;    std::cout << "CMakeTutorial_VERSION_MINOR: " << CMakeTutorialStep1_VERSION_MINOR << std::endl;    std::cout << "STR_TES: " << STR_TEST << std::endl;                    // 充分显示 CXX源文件 可读取 CMake配置文件中变量    std::cout << "测试是否支持中文" << std::endl;    return 1;  }  const double inputValue = std::atof(argv[1]);      // 此处 使用C++中 标准库函数,需要启用C++标准  atof时在C++11之后才有的,如果 使用的 98标准, 此处则报错   const double outputValue = sqrt(inputValue);    //TODO: 使用内置函数   std::cout << "The square root of " << inputValue << " is " << outputValue            << std::endl;  [](){    std::cout << "Test This []()" << std::endl;  }();    // interrobang: 这是 什么写法?    return 0;}/**  interrobang: argv 是参数列表 ,第一个参数是什么?  argc 指代什么? */