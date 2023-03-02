#ifndef AForm_HPP
#define AForm_HPP

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
 public:
  AForm(void);
  AForm(const std::string& name, int sign_grade, int execute_grade);
  AForm(const AForm& src);
  virtual ~AForm(void);
  AForm& operator=(AForm const& rhs);

  const std::string& getName(void) const;

  bool getIsSigned(void) const;
  void setIsSigned(bool status);

  int getSignGrade(void) const;

  int getExecuteGrade(void) const;

  void beSigned(Bureaucrat& person);

  void  checkRequirements(Bureaucrat const& person) const;

  virtual void execute(Bureaucrat const& executor) const = 0;

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class NotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  const std::string name_;
  bool is_signed_;
  const int sign_grade_;
  const int execute_grade_;
};

std::ostream& operator<<(std::ostream& out, const AForm& rhs);

#endif
