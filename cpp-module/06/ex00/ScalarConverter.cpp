#include "ScalarConverter.hpp"

#include <cmath>
#include <iostream>

ScalarConverter::ScalarConverter(void) {}

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

void ScalarConverter::convert(const char* str) {
  long long l_value = std::strtol(str, NULL, 10);
  double d_value = std::strtod(str, NULL);
  float f_value = std::strtof(str, NULL);

  printCharacter(str, l_value, d_value);
  printInt(str, l_value, d_value);
  printFloat(str, f_value);
  printDouble(str, d_value);
}

void ScalarConverter::printCharacter(const char* str, long long l_value,
                                     double d_value) {
  std::cout << "char: ";

  if (std::isnan(d_value) || std::isinf(d_value)) {
    std::cout << "impossible" << std::endl;
    return;
  }

  if (l_value < CHAR_MIN || l_value > CHAR_MAX) {
    std::cout << "overflow" << std::endl;
    return;
  }

  if (std::strlen(str) == 1 && std::isprint(static_cast<int>(str[0])) &&
      std::isdigit(str[0]) == false) {
    std::cout << str[0] << std::endl;
  } else if (std::isprint(static_cast<char>(l_value)) == false) {
    std::cout << "Non displayable" << std::endl;
  } else {
    std::cout << static_cast<char>(l_value) << std::endl;
  }
}

void ScalarConverter::printInt(const char* str, long long l_value,
                               double d_value) {
  std::cout << "int: ";

  if (std::isnan(d_value) || std::isinf(d_value)) {
    std::cout << "impossible" << std::endl;
    return;
  }

  if (std::strlen(str) == 1 &&
      std::isdigit(static_cast<char>(str[0])) == false) {
    std::cout << static_cast<int>(str[0]) << std::endl;
    return;
  }

  if (l_value > INT_MAX || l_value < INT_MIN) {
    std::cout << "overflow" << std::endl;
  } else {
    std::cout << static_cast<int>(l_value) << std::endl;
  }
}

void ScalarConverter::printFloat(const char* str, float f_value) {
  std::cout << "float: ";

  float intPart;
  float fractPart;

  if (std::isnan(f_value) || std::isinf(f_value)) {
    std::cout << f_value << "f" << std::endl;
    return;
  }

  if (std::strlen(str) == 1 &&
      std::isdigit(static_cast<char>(str[0])) == false) {
    std::cout << static_cast<float>(str[0]) << ".0f" << std::endl;
    return;
  }

  fractPart = modf(f_value, &intPart);
  if (fractPart == 0) {
    std::cout << intPart << ".0";
  } else {
    std::cout << f_value;
  }
  std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(const char* str, double d_value) {
  std::cout << "double: ";

  if (std::isnan(d_value) || std::isinf(d_value)) {
    std::cout << d_value << std::endl;
    return;
  }

  if (std::strlen(str) == 1 &&
      std::isdigit(static_cast<char>(str[0])) == false) {
    std::cout << static_cast<double>(str[0]) << ".0" << std::endl;
    return;
  }

  double intPart;
  double fractPart;

  fractPart = modf(d_value, &intPart);
  if (fractPart == 0) {
    std::cout << intPart << ".0";
  } else {
    std::cout << d_value;
  }
  std::cout << std::endl;
}
