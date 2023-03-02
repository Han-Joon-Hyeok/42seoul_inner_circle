#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
    : AForm(name, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src.getName(), 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    RobotomyRequestForm const& rhs) {
  if (this != &rhs) {
    this->setIsSigned(rhs.getIsSigned());
  }
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  this->checkRequirements(executor);

  std::cout << "[RobotomyRequestForm] " << this->getName() << ": Drrr..."
            << std::endl;

  srand(static_cast<unsigned int>(time(NULL)));

  if (rand() % 2 == 0) {
    std::cout << BLUE_TEXT << "[RobotomyRequestForm] " << this->getName()
              << ": is successfully robotomized!" << CUT_TEXT << std::endl;
  } else {
    std::cout << YELLOW_TEXT << "[RobotomyRequestForm] " << this->getName()
              << ": is failed to be robotomized!" << CUT_TEXT << std::endl;
  }
}
