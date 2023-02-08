#include "utils.hpp"
#include <iostream>
#include <iomanip>

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

std::string formatWidth(std::string str) {
  if (str.length() > WIDTH) {
    return (str.substr(0, WIDTH - 1) + ".");
  }
  return (str);
}

void displayTableRow(std::string first_name, std::string last_name,
                      std::string nickname, std::string phone_number,
                      std::string darkest_secret) {
  std::cout << "| ";
  std::cout << std::setw(10) << std::right << formatWidth(first_name) << " | ";
  std::cout << std::setw(10) << std::right << formatWidth(last_name) << " | ";
  std::cout << std::setw(10) << std::right << formatWidth(nickname) << " | ";
  std::cout << std::setw(10) << std::right << formatWidth(phone_number) << " | ";
  std::cout << std::setw(10) << std::right << formatWidth(darkest_secret);
  std::cout << " |" << std::endl;
}
