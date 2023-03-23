#include "RPN.hpp"
#include <string>
#include <iostream>

RPN::RPN(void)
{
}

RPN::RPN(const RPN& src) : stack_(src.stack_)
{
}

RPN::~RPN(void)
{
}

RPN& RPN::operator=(RPN const& rhs)
{
  if (this != &rhs)
  {
    this->stack_ = rhs.stack_;
  }
  return *this;
}

void RPN::calculate(const std::string& expr) {
  std::string::const_iterator it;

  it = expr.begin();

  for (; it != expr.end(); ++it) {
    if (std::isdigit(*it)) {
      if (std::isdigit(*(it + 1))) {
        std::cout << "Error: invalid expression => " << *it << *(it + 1) << std::endl;
        return ;
      }
      this->stack_.push(static_cast<int>(*it) - '0');
    } else if (isArithmeticOperator(*it)) {
      std::cout << *it << std::endl;
    } else if (std::iswspace(*it) == false) {
      std::cout << "Error: invalid expression => " << *it << std::endl;
      return ;
    }
  }

  for (size_t size = this->stack_.size(); size > 0; --size) {
    std::cout << this->stack_.top() << std::endl;
    this->stack_.pop();
  }
}

bool RPN::isArithmeticOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}
