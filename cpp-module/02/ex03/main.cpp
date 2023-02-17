#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed a2(1.01f);
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(Fixed(5.05f) + Fixed(2));
  Fixed const d(Fixed(5.05f) - Fixed(2));
  Fixed const e(Fixed(5.05f) / Fixed(2));
  Fixed const f(Fixed(5.05f) / Fixed(0));

  std::cout << "a: " <<a << std::endl;
  std::cout << "a: " << ++a << std::endl;
  std::cout << "a: " << a << std::endl;
  std::cout << "a: " << a++ << std::endl;
  std::cout << "a: " << a << std::endl;

  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;
  std::cout << "d: " << d << std::endl;
  std::cout << "e: " << e << std::endl;
  std::cout << "f: " << f << std::endl;

  std::cout << std::endl;
  std::cout << "a: " << a << " / b: " << b << std::endl;
  std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
  std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;

  std::cout << std::endl;
  std::cout << "a: " << a << " / a: " << a << std::endl;
  std::cout << "a >= a: " << (a >= a ? "true" : "false") << std::endl;
  std::cout << "a <= a: " << (a <= a ? "true" : "false") << std::endl;

  std::cout << std::endl;
  std::cout << "a: " << a << " / b: " << b << std::endl;
  std::cout << "a == b: " << (a == b ? "true" : "false") << std::endl;
  std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;

  std::cout << std::endl;
  std::cout << "a: " << a << " / a2: " << a2 << std::endl;
  std::cout << "min(a, a2): " << Fixed::min(a, a2) << std::endl;

  std::cout << std::endl;
  std::cout << "b: " << b << " / c: " << c << std::endl;
  std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;

  std::cout << std::endl;
  std::cout << "a: " << a << " / a2: " << a2 << std::endl;
  std::cout << "max(a, a2): " << Fixed::max(a, a2) << std::endl;

  std::cout << std::endl;
  std::cout << "b: " << b << " / c: " << c << std::endl;
  std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

  return (EXIT_SUCCESS);
}
