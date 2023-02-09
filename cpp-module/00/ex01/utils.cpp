#include "utils.hpp"

#include <iomanip>
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

CommandType getCommandType(std::string command) {
  if (command == "ADD") return (ADD);
  if (command == "SEARCH") return (SEARCH);
  if (command == "EXIT") return (EXIT);
  return (NONE);
}

std::string formatWidth(std::string str) {
  if (str.length() > WIDTH) {
    return (str.substr(0, WIDTH - 1) + ".");
  }
  return (str);
}

void displayTableRow(int count, int idx, ...) {
  va_list ap;
  const char *str;

  va_start(ap, idx);
  std::cout << "| ";
  if (idx != HEADER) {
    std::cout << std::setw(10) << std::right << idx << " | ";
  }
  for (int idx = 0; idx < count - 1; idx += 1) {
    str = va_arg(ap, const char *);
    std::cout << std::setw(10) << std::right
              << formatWidth(std::string(str)) << " | ";
  }
  str = va_arg(ap, const char *);
  std::cout << std::setw(10) << std::right
            << formatWidth(std::string(str));
  std::cout << " |" << std::endl;
  va_end(ap);
}
