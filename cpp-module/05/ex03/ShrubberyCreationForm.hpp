#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string& name);
  ShrubberyCreationForm(const ShrubberyCreationForm& src);
  virtual ~ShrubberyCreationForm(void);
  ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

  virtual void execute(Bureaucrat const& executor) const;

 private:
  ShrubberyCreationForm(void);
};

#endif
