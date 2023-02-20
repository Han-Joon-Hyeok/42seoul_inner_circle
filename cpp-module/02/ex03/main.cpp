#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

int main(void) {
  Point const p1(Fixed(0), Fixed(0));
  Point const p2(Fixed(3.3f), Fixed(1.2f));
  Point const p3(Fixed(2.1f), Fixed(3.4f));

  Point const target(Fixed(1.1f), Fixed(1.5f));
  Point const target2(Fixed(-1.1f), Fixed(2.1f));
  Point const target3(Fixed(2.1f), Fixed(3.4f));

  std::cout << "p1: (" << p1.getX() << ", " << p1.getY() << ")" << std::endl;
  std::cout << "p2: (" << p2.getX() << ", " << p2.getY() << ")" << std::endl;
  std::cout << "p3: (" << p3.getX() << ", " << p3.getY() << ")" << std::endl;
  std::cout << "target: (" << target.getX() << ", " << target.getY() << ")" << std::endl;
  std::cout << "target2: (" << target2.getX() << ", " << target2.getY() << ")" << std::endl;
  std::cout << "target3: (" << target3.getX() << ", " << target3.getY() << ")" << std::endl;

  std::cout << "bsp(p1, p2, p3, target): "
            << (bsp(p1, p2, p3, target) ? "true" : "false") << std::endl;
  std::cout << "bsp(p1, p2, p3, target2): "
            << (bsp(p1, p2, p3, target2) ? "true" : "false") << std::endl;
  std::cout << "bsp(p1, p2, p3, target3): "
            << (bsp(p1, p2, p3, target3) ? "true" : "false") << std::endl;

  return (EXIT_SUCCESS);
}
