#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  std::cout << std::string(50, '=') << std::endl;

  // Intern (Success)
  {
    std::cout << GREEN_TEXT << "[Intern] Success case"
              << CUT_TEXT << std::endl;
    Intern intern;
    Bureaucrat b("b", 23);
    AForm*   rrf;

    rrf = intern.makeForm("robotomy request", "Bender");
    b.signForm(*rrf);
    rrf->beSigned(b);
    b.executeForm(*rrf);
    rrf->execute(b);
  }

  std::cout << std::string(50, '=') << std::endl;

  // Intern (Fail)
  try {
    std::cout << RED_TEXT << "[Intern] Fail case"
              << CUT_TEXT << std::endl;
    Intern intern;
    Bureaucrat b("b", 23);
    AForm*   rrf;

    rrf = intern.makeForm("there is no form", "Bender");
    b.signForm(*rrf);
    rrf->beSigned(b);
    b.executeForm(*rrf);
    rrf->execute(b);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;
}
