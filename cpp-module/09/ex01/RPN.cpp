#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN& src) : stack_(src.stack_.begin(), src.stack_.end())
{}

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

}
