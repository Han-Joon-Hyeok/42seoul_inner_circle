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

  static void convert(const char* str);
  static void  printCharacter(const char* str);
  static void  printInt(const char* str);
  static void  printFloat(const char* str);
  static void  printDouble(const char* str);

  static bool isPrintableString(const char* str);
  static bool isValidString(const char* str);
};


std::ostream& operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif
