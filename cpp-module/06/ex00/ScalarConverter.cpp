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
  printInt(str);
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

  std::string converted(str);
  if (converted == "-inff" || converted == "+inff" || converted == "inff" ||
      converted == "-nan" || converted == "+nan" || converted == "nan" ||
      converted == "-nanf" || converted == "+nanf" || converted == "nanf") {
    std::cout << "impossible" << std::endl;
    return;
  }

  char* pos = NULL;
  std::strtod(str, &pos);
  double value = std::strtod(str, &pos);

  if (std::strlen(str) == 1 && std::isprint(value) == true) {
    std::cout << str[0] << std::endl;
  } else if (std::isprint(value) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(value) << std::endl;
  }
}

void ScalarConverter::printInt(const char* str) {
  std::cout << "int: ";

  std::string converted(str);
  if (converted == "-inff" || converted == "+inff" || converted == "inff" ||
      converted == "-nan" || converted == "+nan" || converted == "nan" ||
      converted == "-nanf" || converted == "+nanf" || converted == "nanf") {
    std::cout << "impossible" << std::endl;
    return;
  }

  char* pos = NULL;
  std::strtod(str, &pos);
  long long value = std::strtoll(str, &pos, 10);
  if (value > INT_MAX || value < INT_MIN) {
    std::cout << "overflow" << std::endl;
  } else {
    std::cout << value << std::endl;
  }
}

// void  ScalarConverter::printFloat(const char* str) {

// }

// void  ScalarConverter::printDouble(const char* str) {

// }
