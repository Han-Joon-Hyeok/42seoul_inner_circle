#include "Bureaucrat.hpp"

#include <iostream>

#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
  if (grade < 1) {
    throw GradeTooHighException();
  } else if (grade > 150) {
    throw GradeTooLowException();
  } else {
    grade_ = grade;
  }
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) { *this = src; }

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
  if (this != &rhs) {
    this->grade_ = rhs.grade_;
  }
  return *this;
}

const std::string& Bureaucrat::getName(void) const { return (name_); }

int Bureaucrat::getGrade(void) const { return (grade_); }

void Bureaucrat::upGrade(void) {
  if (grade_ - 1 == 0) {
    throw GradeTooHighException();
  }
  grade_ -= 1;
}

void Bureaucrat::downGrade(void) {
  if (grade_ + 1 == 151) {
    throw GradeTooLowException();
  }
  grade_ += 1;
}

void Bureaucrat::signForm(AForm& form) {
  if (form.getSignGrade() < this->getGrade()) {
    std::cout << this->getName() << " couldn't sign " << form.getName()
              << " because " << this->getName() << " grade is lower than form"
              << " (" << this->getName() << ": " << this->getGrade() << ", "
              << form.getName() << ": " << form.getSignGrade() << ")"
              << std::endl;
    return;
  }
  if (form.getIsSigned() == true) {
    std::cout << this->getName() << " can't sign " << form.getName()
              << " because it is already signed!" << std::endl;
  } else {
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const& form) {
  if (this->getGrade() > form.getExecuteGrade()) {
    std::cout << this->getName() << " couldn't execute " << form.getName()
              << " because " << this->getName() << " grade is lower than form"
              << " (" << this->getName() << ": " << this->getGrade() << ", "
              << form.getName() << ": " << form.getExecuteGrade() << ")"
              << std::endl;
  } else {
    std::cout << this->getName() << " executed " << form.getName() << std::endl;
  }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("[Bureaucrat] Grade is too high");
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("[Bureaucrat] Grade is too low");
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {
  out << rhs.getName() + ", bureaucrat grade " +
             std::to_string(rhs.getGrade()) + ".";
  return (out);
}
