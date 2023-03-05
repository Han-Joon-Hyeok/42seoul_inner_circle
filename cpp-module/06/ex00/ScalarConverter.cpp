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

void ScalarConverter::convert(const std::string& str) {
  std::cout << str << std::endl;
}

bool ScalarConverter::isPrintableString(const std::string& str) {
  for (int idx = 0; idx < static_cast<int>(str.size()); idx += 1) {
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

  if (len == 0) {
    return (true);
  }
  if (*pos != 'f' || len >= 2) {
    return (false);
  }
  return (true);
}
