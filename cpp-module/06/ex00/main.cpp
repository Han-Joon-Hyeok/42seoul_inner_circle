#include <iostream>

#include "ScalarConverter.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Please enter only one argument. [./convert value]" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (ScalarConverter::isPrintableString(argv[1]) == false) {
    std::cout << "There is non printable character" << std::endl;
    exit(EXIT_FAILURE);
  }

  if (ScalarConverter::isValidString(argv[1]) == false) {
    std::cout << "There is invalid character" << std::endl;
    exit(EXIT_FAILURE);
  }

  ScalarConverter::convert(argv[1]);
  std::cout << std::string(50, '=') << std::endl;

}
