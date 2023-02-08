#include "utils.hpp"
#include <iostream>

void printErrorMessage(std::string message, std::string arg) {
  std::cout << YELLOW_TEXT << ERROR_HEADER << CUT_TEXT << message << ": " << arg
            << std::endl;
}

void showPrompt(std::string message, std::string &input) {
  std::cout << GREEN_TEXT << message << CUT_TEXT;
  std::getline(std::cin, input);
}

void printColorMessage(int count, std::string color, ...) {
  va_list     ap;
  std::string str;

  va_start(ap, color);
  std::cout << color;
  for (int idx = 0; idx < count; idx += 1) {
    str = va_arg(ap, const char *);
    std::cout << str;
  }
  std::cout << CUT_TEXT << std::endl;
  va_end(ap);
}

void printWarnMessage(std::string message, std::string arg) {
  std::cout << RED_TEXT << WARN_HEADER << CUT_TEXT << message << ": " << arg
            << std::endl;
}
