#include "Intern.hpp"

#include <iostream>

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

Intern::Intern(void) {}

Intern::Intern(const Intern& src) { (void)src; }

Intern::~Intern(void) {}

Intern& Intern::operator=(Intern const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

int Intern::checkFormType(const std::string& type) {
  int type_num = -1;

  std::string types[NUMBER_OF_FORM_TYPE] = {
      "robotomy request", "shrubbery creation", "presidential pardon"};

  for (int idx = 0; idx < NUMBER_OF_FORM_TYPE; idx += 1) {
    if (types[idx] == type) {
      type_num = idx;
      break;
    }
  }

  return (type_num);
}

AForm* Intern::makeForm(const std::string& form_type,
                        const std::string& form_name) {
  switch (checkFormType(form_type)) {
    case ROBOTOMY_REQUEST:
      return (new RobotomyRequestForm(form_name));
      break;

    case SHRUBBERY_CREATION:
      return (new ShrubberyCreationForm(form_name));
      break;

    case PRESIDENTIAL_PARDON:
      return (new PresidentialPardonForm(form_name));
      break;

    default:
      std::cout << "There is no " << YELLOW_TEXT << form_type << CUT_TEXT
                << " [robotomy request, shrubbery creation, presidential pardon]"
                << std::endl;
      throw (Intern::NotExistedFormException());
      break;
  }
}

const char* Intern::NotExistedFormException::what() const throw() {
  return ("[Intern] This is not existed form type");
};
