#include "Form.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int sign_grade, int execute_grade)
    : name_(name),
      is_signed_(false),
      sign_grade_(sign_grade),
      execute_grade_(execute_grade) {
  if (sign_grade < 1 || execute_grade < 1) {
    throw Form::GradeTooHighException();
  }
  if (sign_grade > 150 || execute_grade > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(const Form& src)
    : name_(src.getName()),
      is_signed_(src.getIsSigned()),
      sign_grade_(getSignGrade()),
      execute_grade_(getExecuteGrade()) {}

Form::~Form(void) {}

Form& Form::operator=(Form const& rhs) {
  if (this != &rhs) {
    this->setIsSigned(rhs.getIsSigned());
  }
  return *this;
}

bool Form::getIsSigned(void) const { return (is_signed_); }

const std::string& Form::getName(void) const { return (name_); }

int Form::getSignGrade(void) const { return (sign_grade_); }

int Form::getExecuteGrade(void) const { return (execute_grade_); }

void Form::setIsSigned(bool status) { is_signed_ = status; }

void Form::beSigned(Bureaucrat& person) {
  if (person.getGrade() > this->getSignGrade()) {
    throw(Form::GradeTooLowException());
  }
  if (this->getIsSigned() == true) {
    std::cout << this->getName() << " is already signed!" << std::endl;
  } else {
    std::cout << "Successfully form is signed by " + person.getName()
              << std::endl;
    this->setIsSigned(true);
  }
}

const char* Form::GradeTooHighException::what() const throw() {
  return ("[Form] Grade is too high");
};

const char* Form::GradeTooLowException::what() const throw() {
  return ("[Form] Grade is too low");
};

std::ostream& operator<<(std::ostream& out, const Form& rhs) {
  out << rhs.getName() +
             ", form sign grade: " + std::to_string(rhs.getSignGrade()) +
             ", execute grade: " + std::to_string(rhs.getExecuteGrade()) +
             " (is_signed: " + (rhs.getIsSigned() ? "true" : "false") + ")";
  return (out);
}
