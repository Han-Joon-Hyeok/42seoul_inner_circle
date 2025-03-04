#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <string>

class ScalarConverter {
 private:
  ScalarConverter(void);

 public:
  static void setValue(const double value);
  static double getValue(void);

  static void convert(const char* str);
  static void printCharacter(const char* str, long long l_value,
                             double d_value);
  static void printInt(const char* str, long long l_value, double d_value);
  static void printFloat(const char* str, float f_value);
  static void printDouble(const char* str, double d_value);

  static bool isPrintableString(const char* str);
  static bool isValidString(const char* str);
};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif
