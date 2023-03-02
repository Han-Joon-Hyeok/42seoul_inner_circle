#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(const std::string& name, int sign_grade, int execute_grade)
    : name_(name),
      is_signed_(false),
      sign_grade_(sign_grade),
      execute_grade_(execute_grade) {
  if (sign_grade < 1 || execute_grade < 1) {
    throw AForm::GradeTooHighException();
  }
  if (sign_grade > 150 || execute_grade > 150) {
    throw AForm::GradeTooLowException();
  }
}

AForm::AForm(const AForm& src)
    : name_(src.getName()),
      is_signed_(src.getIsSigned()),
      sign_grade_(getSignGrade()),
      execute_grade_(getExecuteGrade()) {}

AForm::~AForm(void) {}

AForm& AForm::operator=(AForm const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

bool AForm::getIsSigned(void) const { return (is_signed_); }

const std::string& AForm::getName(void) const { return (name_); }

int AForm::getSignGrade(void) const { return (sign_grade_); }

int AForm::getExecuteGrade(void) const { return (execute_grade_); }

void AForm::setIsSigned(bool status) { is_signed_ = status; }

void AForm::beSigned(Bureaucrat& person) {
  if (person.getGrade() > this->getSignGrade()) {
    throw(AForm::GradeTooLowException());
  }
  if (this->getIsSigned() == true) {
    std::cout << this->getName() << " is already signed!" << std::endl;
  } else {
    std::cout << "Successfully form is signed by " + person.getName()
              << std::endl;
    this->setIsSigned(true);
  }
}

void  AForm::checkRequirements(Bureaucrat const& person) const {
  if (this->getIsSigned() == false) {
    throw(AForm::NotSignedException());
  }
  if (person.getGrade() > this->getExecuteGrade()) {
    throw(AForm::GradeTooLowException());
  }
}

const char* AForm::GradeTooHighException::what() const throw() {
  return ("[AForm] Grade is too high");
};

const char* AForm::GradeTooLowException::what() const throw() {
  return ("[AForm] Grade is too low");
};

const char* AForm::NotSignedException::what() const throw() {
  return ("[AForm] AForm is not signed yet");
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs) {
  out << rhs.getName() +
             ", form sign grade: " + std::to_string(rhs.getSignGrade()) +
             ", execute grade: " + std::to_string(rhs.getExecuteGrade()) +
             " (is_signed: " + (rhs.getIsSigned() ? "true" : "false") + ")";
  return (out);
}
