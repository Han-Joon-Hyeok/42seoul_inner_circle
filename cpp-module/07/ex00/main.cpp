#include <iostream>

#include "whatever.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  std::cout << GREEN_TEXT << "SWAP TEST" << CUT_TEXT << std::endl;

  {
    std::cout << YELLOW_TEXT << "int" << CUT_TEXT << std::endl;

    int num1 = 42;
    int num2 = 24;

    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
    ::swap(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
  }

  {
    std::cout << YELLOW_TEXT << "string" << CUT_TEXT << std::endl;
    std::string str1 = "hello";
    std::string str2 = "world";

    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl;
    ::swap(str1, str2);
    std::cout << "str1: " << str1 << " str2: " << str2 << std::endl;
  }


}
