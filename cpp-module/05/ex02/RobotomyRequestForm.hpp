#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(const std::string& name);
  RobotomyRequestForm(const RobotomyRequestForm& src);
  virtual ~RobotomyRequestForm(void);
  RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

  virtual void execute(Bureaucrat const& executor) const;

 private:
  RobotomyRequestForm(void);
};

#endif
