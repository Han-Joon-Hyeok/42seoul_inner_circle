#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  std::cout << std::string(50, '=') << std::endl;

  // Too high exception (sign grade)
  try {
    std::cout << GREEN_TEXT << "FORM SIGN GRADE TOO HIGH" << CUT_TEXT << std::endl;
    Form f("form", 0, 42);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT
              << " sign grade: 0 is too high" << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too low exception (sign grade)
  try {
    std::cout << GREEN_TEXT << "FORM SIGN GRADE TOO LOW" << CUT_TEXT << std::endl;
    Form f("form", 200, 42);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT
              << " sign grade: 200 is too low" << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too high exception (execute grade)
  try {
    std::cout << GREEN_TEXT << "FORM EXECUTE GRADE TOO HIGH" << CUT_TEXT << std::endl;
    Form f("form", 42, 0);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT
              << " execute grade: 0 is too high" << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too low exception (execute grade)
  try {
    std::cout << GREEN_TEXT << "FORM EXECUTE GRADE TOO LOW" << CUT_TEXT << std::endl;
    Form f("form", 42, 200);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT
              << " execute grade: 200 is too low" << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Too low exception (Form::beSigned() function)
  try {
    std::cout << GREEN_TEXT << "Bureaucrat GRADE LOW THAN Form" << CUT_TEXT << std::endl;

    Form f("An example form", 42, 42);
    Bureaucrat b("joonhan", 50);

    std::cout << f << std::endl;
    std::cout << b << std::endl;

    b.signForm(f);
    f.beSigned(b);
  } catch (std::exception& e) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT
              << " sign grade: 50 is low than form sign grade" << std::endl;
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Suceess case
  try {
    std::cout << GREEN_TEXT << "Successful case" << CUT_TEXT << std::endl;

    Form f("An example form", 42, 42);
    Bureaucrat b("joonhan", 1);

    std::cout << f << std::endl;
    std::cout << b << std::endl;

    b.signForm(f);
    f.beSigned(b);

    std::cout << f << std::endl;

    std::cout << std::endl;

    std::cout << YELLOW_TEXT << "Trying to sign already signed form" << CUT_TEXT << std::endl;
    b.signForm(f);
    f.beSigned(b);
  } catch (...) {
    std::cout << RED_TEXT << "[Error]" << CUT_TEXT
              << "Something unknown error occurs" << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;
}
