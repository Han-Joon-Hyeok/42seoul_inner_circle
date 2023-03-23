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
      std::cout << *it << std::endl;
    } else if (isArithmeticOperator(*it)) {
      std::cout << *it << std::endl;
    } else if (std::iswspace(*it) == false) {
      std::cout << "Error: invalid expression => " << *it << std::endl;
      return ;
    }
  }
}

bool RPN::isArithmeticOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}
