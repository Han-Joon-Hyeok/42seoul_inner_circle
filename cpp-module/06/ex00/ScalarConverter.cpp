#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& src) { (void)src; }

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

void ScalarConverter::convert(const std::string& str) { (void)str; }

bool ScalarConverter::isPrintableString(const std::string& str) {
  for (int idx = 0; idx < static_cast<int>(str.size()); idx += 1) {
    if (std::isprint(str[idx]) == false) {
      return (false);
    }
  }
  return (true);
}

bool ScalarConverter::isValidString(const std::string& str) {
  int dot_count = 0;
  int float_count = 0;

  for (int idx = 0; idx < static_cast<int>(str.size()); idx += 1) {
    if (str[idx] == '.') {
      dot_count += 1;
      if (dot_count == 2) {
        setExceptionArg(str);
        return (false);
      }
    } else if (str[idx] == 'f') {
      float_count += 1;
      if (float_count == 2) {
        setExceptionArg(str);
        return (false);
      }
    } else if (std::isdigit(str[idx]) == false) {
      return (false);
    }
  }
  return (true);
}

void ScalarConverter::setExceptionArg(const std::string& arg) {
  exception_arg_ = arg;
}

const char* ScalarConverter::NonPrintableException::what() const throw() {
  return ("[EXCEPTION] There is non printable character");
};

const char* ScalarConverter::InvalidStringException::what() const throw() {
  return ("[EXCEPTION] There is invalid character");
};
