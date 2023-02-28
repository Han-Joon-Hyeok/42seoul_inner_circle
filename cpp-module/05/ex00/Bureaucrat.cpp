#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade): name_(name) {
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

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high");
};

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low");
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs) {
  out << rhs.getName() + ", bureaucrat grade " +
             std::to_string(rhs.getGrade()) + ".";
  return (out);
}
