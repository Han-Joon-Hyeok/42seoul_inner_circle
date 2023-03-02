#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  // std::cout << std::string(50, '=') << std::endl;

  // // ShrubberyCreationForm (Success)
  // try {
  //   std::cout << GREEN_TEXT << "[ShrubberyCreationForm] Success case"
  //             << CUT_TEXT << std::endl;
  //   ShrubberyCreationForm sf("sf");
  //   Bureaucrat b("b", 130);

  //   b.signForm(sf);
  //   sf.beSigned(b);
  //   sf.execute(b);
  // } catch (std::exception& e) {
  //   std::cout << e.what() << std::endl;
  // }

  // std::cout << std::string(50, '=') << std::endl;

  // // ShrubberyCreationForm (Fail)
  // try {
  //   std::cout << RED_TEXT << "[ShrubberyCreationForm] Fail case" << CUT_TEXT
  //             << std::endl;
  //   ShrubberyCreationForm sf("sf");
  //   Bureaucrat b2("b2", 130);

  //   b2.signForm(sf);
  //   sf.execute(b2); // throw AForm::NotSignedException
  //   sf.beSigned(b2);
  // } catch (std::exception& e) {
  //   std::cout << e.what() << std::endl;
  // }

  // std::cout << std::string(50, '=') << std::endl;

  // // RobotomyRequestForm (Success)
  // try {
  //   std::cout << GREEN_TEXT << "[RobotomyRequestForm] Success case" << CUT_TEXT
  //             << std::endl;
  //   RobotomyRequestForm rrf("rrf");
  //   Bureaucrat b("b", 40);

  //   b.signForm(rrf);
  //   rrf.beSigned(b);
  //   rrf.execute(b);
  // } catch (std::exception& e) {
  //   std::cout << e.what() << std::endl;
  // }

  // std::cout << std::string(50, '=') << std::endl;

  // // RobotomyRequestForm (Fail)
  // try {
  //   std::cout << GREEN_TEXT << "[RobotomyRequestForm] Fail case" << CUT_TEXT
  //             << std::endl;
  //   RobotomyRequestForm rrf("rrf");
  //   Bureaucrat b("b", 50);

  //   b.signForm(rrf);
  //   rrf.beSigned(b);
  //   rrf.execute(b);
  // } catch (std::exception& e) {
  //   std::cout << e.what() << std::endl;
  // }

  std::cout << std::string(50, '=') << std::endl;

  // PresidentialPardonForm (Success)
  try {
    std::cout << GREEN_TEXT << "[PresidentialPardonForm] Success case" << CUT_TEXT
              << std::endl;
    PresidentialPardonForm ppf("ppf");
    Bureaucrat b("b", 3);

    b.signForm(ppf);
    ppf.beSigned(b);
    ppf.execute(b);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // PresidentialPardonForm (Fail)
  try {
    std::cout << RED_TEXT << "[PresidentialPardonForm] Fail case" << CUT_TEXT
              << std::endl;
    PresidentialPardonForm ppf("ppf");
    Bureaucrat b("b", 15);

    b.signForm(ppf);
    ppf.beSigned(b);
    ppf.execute(b);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;
}
