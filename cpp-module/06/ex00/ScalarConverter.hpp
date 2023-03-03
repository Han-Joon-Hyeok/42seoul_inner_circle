#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <string>
#include <exception>

class ScalarConverter {
 private:
  static std::string exception_arg_;
 public:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& src);
  ~ScalarConverter(void);
  ScalarConverter& operator=(ScalarConverter const& rhs);

  static void convert(const std::string& arg);
  static bool isPrintableString(const std::string& arg);
  static bool isValidString(const std::string& arg);

  void  setExceptionArg(const std::string& arg);

  class NonPrintableException : public std::exception {
			public:
				virtual const char* what() const throw();
    };

  class InvalidStringException : public std::exception {
			public:
				virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const ScalarConverter& rhs);

#endif
