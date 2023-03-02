#ifndef Intern_HPP
#define Intern_HPP

#include <string>

#define NUMBER_OF_FORM_TYPE 3

class AForm;

enum { ROBOTOMY_REQUEST, SHRUBBERY_CREATION, PRESIDENTIAL_PARDON };

class Intern {
 public:
  Intern(void);
  Intern(const Intern& src);
  ~Intern(void);
  Intern& operator=(Intern const& rhs);

  int checkFormType(const std::string& type);
  AForm* makeForm(const std::string& form_type, const std::string& form_name);

  class NotExistedFormException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif
