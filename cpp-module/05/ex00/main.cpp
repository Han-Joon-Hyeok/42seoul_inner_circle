#include <iostream>

#include "Bureaucrat.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  {
    std::cout << std::string(50, '=') << std::endl;
    std::cout << GREEN_TEXT << "COPY ASSIGNMENT OPERATOR" << CUT_TEXT
              << std::endl;

    Bureaucrat b1("b1", 3);
    Bureaucrat b2("b2", 5);

    std::cout << YELLOW_TEXT << "BEFORE COPY" << CUT_TEXT << std::endl;
    std::cout << b2 << std::endl;

    b2 = b1;

    std::cout << YELLOW_TEXT << "AFTER COPY" << CUT_TEXT << std::endl;
    std::cout << b2 << std::endl;
    std::cout << std::string(50, '=') << std::endl;
  }
  {
    std::cout << GREEN_TEXT << "COPY CONSTRUCTOR (b1->b2)" << CUT_TEXT << std::endl;

    Bureaucrat b1("b1", 3);
    Bureaucrat b2(b1);

    std::cout << b2 << std::endl;
    std::cout << std::string(50, '=') << std::endl;
  }

  // Too high exception
  try {
    Bureaucrat b1("b1", 0);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT << " grade: 0 is too high"
              << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too high exception (with increment function)
  try {
    Bureaucrat b2("b2", 5);
    while (true) {
      std::cout << b2 << std::endl;
      b2.upGrade();
    }
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT << " Can't upgrade over 1"
              << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too low exception
  try {
    Bureaucrat b3("b3", 151);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT << " grade 151 is too low"
              << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too low exception (with decrement function)
  try {
    Bureaucrat b4("b4", 147);
    while (true) {
      std::cout << b4 << std::endl;
      b4.downGrade();
    }
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT << " Can't upgrade over 1"
              << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;
}
