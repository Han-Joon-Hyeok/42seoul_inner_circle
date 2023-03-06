#include "ScalarConverter.hpp"

#include <iostream>

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

void ScalarConverter::convert(const char* str) {
  std::cout << str << std::endl;
  printCharacter(str);
}

bool ScalarConverter::isPrintableString(const char* str) {
  for (int idx = 0; idx < static_cast<int>(std::strlen(str)); idx += 1) {
    if (std::isprint(str[idx]) == false) {
      return (false);
    }
  }
  return (true);
}

bool ScalarConverter::isValidString(const char* str) {
  char* pos = NULL;
  std::strtod(str, &pos);
  size_t len = std::strlen(pos);

  if (len == 0 || std::strlen(str) == 1) {
    return (true);
  }
  if (*pos != 'f' || len >= 2) {
    return (false);
  }
  return (true);
}

void ScalarConverter::printCharacter(const char* str) {
  std::cout << "char: ";

  if (std::strlen(str) == 1) {
    std::cout << str[0] << std::endl;
    return ;
  }

  char* pos = NULL;
  std::strtod(str, &pos);
  double value = std::strtod(str, &pos);

  if (std::isprint(value) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(value) << std::endl;
  }
}

// void  ScalarConverter::printInt(const std::string& str) {

// }

// void  ScalarConverter::printFloat(const std::string& str) {

// }

// void  ScalarConverter::printDouble(const std::string& str) {

// }
