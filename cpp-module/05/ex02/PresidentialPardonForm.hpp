#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string& name);
  PresidentialPardonForm(const PresidentialPardonForm& src);
  virtual ~PresidentialPardonForm(void);
  PresidentialPardonForm& operator=(PresidentialPardonForm const& rhs);

  virtual void execute(Bureaucrat const& executor) const;

 private:
  PresidentialPardonForm(void);
};

#endif
