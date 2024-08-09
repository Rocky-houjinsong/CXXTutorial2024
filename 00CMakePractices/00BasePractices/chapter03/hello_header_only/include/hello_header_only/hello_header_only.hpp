#pragma once

#include <iostream> // for std::cout , std::endl
#include <string>

namespace hello_header_only
{
    void print_hello(const std::string& name) {
        std::cout << "Hello " << name << " from a header only library" << std::endl;
    }
}