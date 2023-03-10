#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Generator.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  srand(time(NULL));
  {
    std::cout << std::string(50, '=') << std::endl;

    std::cout << GREEN_TEXT << "Pointer Identify" << CUT_TEXT << std::endl;
    Base* instance = Generator::generate();

    Generator::identify(instance);
    delete instance;
  }
  {
    std::cout << std::string(50, '=') << std::endl;
    std::cout << GREEN_TEXT << "Reference Identify" << CUT_TEXT << std::endl;
    Base* instance = Generator::generate();

    Generator::identify(*instance);
    delete instance;
  }
  return (0);
}
