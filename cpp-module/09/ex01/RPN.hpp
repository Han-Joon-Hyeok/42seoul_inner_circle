#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

enum EOperatorType {
  PLUS,
  MINUS,
  MULTIPLY,
  DIVIDE,
  ERROR
};

class RPN
{
  private:
    std::stack<double> stack_;

  public:
    RPN(void);
    RPN(const RPN& src);
    ~RPN(void);
    RPN& operator=(RPN const& rhs);

    void calculate(const std::string& expr);
    bool isArithmeticOperator(char c);
    EOperatorType getOperatorType(char c);
};

#endif
