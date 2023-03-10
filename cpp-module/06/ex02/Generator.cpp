#include "Generator.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

enum EClassType { CLASS_A, CLASS_B, CLASS_C };

Base* Generator::generate(void) {
  switch (rand() % 3) {
    case CLASS_A:
      return (new A());
    case CLASS_B:
      return (new B());
    default:
      return (new C());
  }
}

void Generator::identify(Base* p) {
  if (dynamic_cast<A*>(p)) {
    std::cout << "This is A class" << std::endl;
  } else if (dynamic_cast<B*>(p)) {
    std::cout << "This is B class" << std::endl;
  } else {
    std::cout << "This is C class" << std::endl;
  }
}

void downcastToChild(Base& p, EClassType type) {
  try {
    switch (type) {
      case CLASS_A:
        (void)dynamic_cast<A&>(p);
        std::cout << "This is A class" << std::endl;
        break;
      case CLASS_B:
        (void)dynamic_cast<B&>(p);
        std::cout << "This is B class" << std::endl;
        break;
      default:
        (void)dynamic_cast<C&>(p);
        std::cout << "This is C class" << std::endl;
        break;
    }
  } catch (std::bad_cast& e) {
    e.what();
  }
}

/*
  Reference 변수는 포인터처럼 NULL 값을 가지기 못한다.
  따라서 때문에 try ~ catch 로 확인한다.
*/
void Generator::identify(Base& p) {
  downcastToChild(p, CLASS_A);
  downcastToChild(p, CLASS_B);
  downcastToChild(p, CLASS_C);
}
