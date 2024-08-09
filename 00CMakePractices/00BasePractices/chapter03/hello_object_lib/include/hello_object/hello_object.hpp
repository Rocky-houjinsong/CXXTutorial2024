#pragma once  

#include <string>

namespace hello_object {
/// Example class that is explicitly exported to a dll
class HelloObject {
public:
  HelloObject(const std::string &name) : m_name{name} {} //语法 ?

  void greet() const;     //const 该函数为查询函数

private:
  const std::string m_name;
};
} // namespace hello_object