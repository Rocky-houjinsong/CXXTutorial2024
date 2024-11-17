// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "TutorialConfig.hxx"


#ifdef USE_MYMATH
#include "MathFunctions.hxx"
#endif
int main(int argc, char* argv[])
{
  if (argc < 2) {
    std::cout << argv[0] << " Version " << CMakeTutorialStep2_VERSION_MAJOR << "."
              << CMakeTutorialStep2_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  const double inputValue = std::stod(argv[1]);
 

  #ifdef USE_MYMATH
        const double outputValue = mathfunctions::sqrt(inputValue);
  #else
        const double outputValue = sqrt(inputValue);
  #endif
  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
