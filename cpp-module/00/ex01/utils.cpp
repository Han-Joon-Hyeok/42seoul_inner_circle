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

void printColorMessage(std::string color, std::string message) {
  std::cout << color << message << CUT_TEXT << std::endl;
}

void printWarnMessage(std::string message, std::string arg) {
  std::cout << RED_TEXT << WARN_HEADER << CUT_TEXT << message << ": " << arg
            << std::endl;
}
