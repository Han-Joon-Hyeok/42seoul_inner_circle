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
  double num1;
  double num2;
  double result;

  it = expr.begin();

  for (; it != expr.end(); ++it) {
    if (std::isdigit(*it)) {
      if (std::isdigit(*(it + 1))) {
        std::cout << "Error: number can be only [0 ~ 9] => " << *it << *(it + 1)
                  << std::endl;
        return;
      }
      this->stack_.push(static_cast<int>(*it) - '0');
    } else if (isArithmeticOperator(*it)) {
      num2 = this->stack_.top();
      this->stack_.pop();
      num1 = this->stack_.top();
      this->stack_.pop();
      switch (getOperatorType(*it)) {
        case PLUS:
          result = num1 + num2;
          break;
        case MINUS:
          result = num1 - num2;
          break;
        case MULTIPLY:
          result = num1 * num2;
          break;
        case DIVIDE:
          if (num2 == 0) {
            std::cout << "Error: can't divide by 0 => " << num1 << " / " << num2
                      << std::endl;
            return;
          }
          result = num1 / num2;
          break;
        default:
          std::cout << "Error: invalid operator => " << *it << std::endl;
          return;
      }
      this->stack_.push(result);
    } else if (std::iswspace(*it) == false) {
      std::cout << "Error: invalid expression => " << *it << std::endl;
      return;
    }
  }
  if (this->stack_.size() != 1) {
    std::cout << "Error: stack size is not 1 => " << expr << std::endl;
    return ;
  }
  std::cout << this->stack_.top() << std::endl;
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
