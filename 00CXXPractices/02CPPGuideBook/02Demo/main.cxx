#include <iostream>
#include <tuple>
using namespace std;
/** 元组  C++11*/
std::tuple<int, double, std::string>

/** 结构化绑定 - C++17 */
processValues(int a){
    return { a * 2, a / 2.0, "Processed" };
}

int main()
{
    auto [multiplied, divided, Status] = processValues(10);

    std::cout << multiplied << std::endl;
    std::cout << divided << std::endl;
    std::cout << Status << std::endl;    
}

