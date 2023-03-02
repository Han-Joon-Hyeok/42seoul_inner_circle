#include "PresidentialPardonForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
    : AForm(name, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& src)
    : AForm(src.getName(), 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    PresidentialPardonForm const& rhs) {
  if (this != &rhs) {
    this->setIsSigned(rhs.getIsSigned());
  }
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  this->checkRequirements(executor);

  std::cout << BLUE_TEXT << "[PresidentialPardonForm] " << this->getName()
            << ": is pardoned by Zaphod Beeblebrox!" << CUT_TEXT << std::endl;
}
