#include <cmath>
#include <iostream>
#include <string>

// 引入由配置文件生成的 头文件
#include "CMakeTutorialConfig.h"


int main(int argc, char* argv[])
{
  if (argc < 2) {

    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    std::cout << "__cplusplus: " << __cplusplus << std::endl;
    std::cout << "CMakeTutorial_VERSION_MAJOR: " << CMakeTutorialStep1_VERSION_MAJOR << std::endl;
    std::cout << "CMakeTutorial_VERSION_MINOR: " << CMakeTutorialStep1_VERSION_MINOR << std::endl;
    std::cout << "STR_TES: " << STR_TEST << std::endl;
    std::cout << "测试是否支持中文" << std::endl;
    return 1;
  }

  // TODO 4: Replace atof(argv[1]) with std::stod(argv[1])
  const double inputValue = std::atof(argv[1]);      // 此处 使用C++中 标准库函数,需要启用C++标准  atof时在C++11之后才有的,如果 使用的 98标准, 此处则报错 


  // calculate square root
  const double outputValue = sqrt(inputValue);
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
