#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <string>

class ScalarConverter {
 public:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& src);
  ~ScalarConverter(void);
  ScalarConverter& operator=(ScalarConverter const& rhs);

  static void setValue(const double value);
  static double getValue(void);
  static void convert(const std::string& arg);
  static bool isPrintableString(const std::string& arg);
  static bool isValidString(const char* str);

  void  setExceptionArg(const std::string& arg);
};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif
