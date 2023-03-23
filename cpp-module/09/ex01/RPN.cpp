#include "RPN.hpp"

#include <iostream>
#include <string>

RPN::RPN(void) {}

RPN::RPN(const RPN& src) : stack_(src.stack_) {}

RPN::~RPN(void) {}

RPN& RPN::operator=(RPN const& rhs) {
  if (this != &rhs) {
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
        std::cout << "Error: invalid expression => " << *it << *(it + 1)
                  << std::endl;
        return;
      }
      this->stack_.push(static_cast<int>(*it) - '0');
    } else if (isArithmeticOperator(*it)) {
      switch (getOperatorType(*it)) {
        case PLUS:
          std::cout << *it << std::endl;
          break;
        case MINUS:
          std::cout << *it << std::endl;
          break;
        case MULTIPLY:
          std::cout << *it << std::endl;
          break;
        case DIVIDE:
          std::cout << *it << std::endl;
          break;
        default:
          break;
      }
    } else if (std::iswspace(*it) == false) {
      std::cout << "Error: invalid expression => " << *it << std::endl;
      return;
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

EOperatorType RPN::getOperatorType(char c) {
  char operators[4] = {'+', '-', '*', '/'};

  for (int idx = 0; idx < 4; idx += 1) {
    if (operators[idx] == c) {
      return (static_cast<EOperatorType>(idx));
    }
  }
  return (ERROR);
}
