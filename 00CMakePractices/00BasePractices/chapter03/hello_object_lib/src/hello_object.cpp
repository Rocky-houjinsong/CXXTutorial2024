#include <hello_object/hello_object.hpp>

#include <iostream>

namespace hello_object {
void HelloObject::greet() const {
  std::cout << "Hello " << m_name << " From an object library" << std::endl;
}
} // namespace hello_object