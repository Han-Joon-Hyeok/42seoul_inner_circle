#include <iostream>

#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {

  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << std::string(50, '=') << std::endl;
  std::cout << YELLOW_TEXT << "ADDRESS" << CUT_TEXT << std::endl;
  std::cout << "str      : "<< GREEN_TEXT << &str << CUT_TEXT << std::endl;
  std::cout << "stringPTR: "<< GREEN_TEXT << &stringPTR << CUT_TEXT << std::endl;
  std::cout << "stringREF: "<< GREEN_TEXT << &stringREF << CUT_TEXT << std::endl;
  std::cout << std::string(50, '=') << std::endl;

  std::cout << std::string(50, '=') << std::endl;
  std::cout << YELLOW_TEXT << "VALUE" << CUT_TEXT << std::endl;
  std::cout << "stringPTR: "<< GREEN_TEXT << *stringPTR << CUT_TEXT << std::endl;
  std::cout << "stringREF: "<< GREEN_TEXT << stringREF << CUT_TEXT << std::endl;
  std::cout << std::string(50, '=') << std::endl;

  return (EXIT_SUCCESS);
}
