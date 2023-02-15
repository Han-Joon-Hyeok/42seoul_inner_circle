#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;    // Default constructor
  Fixed b(a); // Copy constructor
  Fixed c;    // Default constructor

  c = b;      // Copy assignment constructor

  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;

  return (EXIT_SUCCESS);
}
