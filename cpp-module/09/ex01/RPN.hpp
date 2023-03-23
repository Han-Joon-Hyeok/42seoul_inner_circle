#ifndef RPN_HPP
# define RPN_HPP

#include <stack>

class RPN
{
  private:
    std::stack<unsigned int> stack_;

  public:
    RPN(void);
    RPN(const RPN& src);
    ~RPN(void);
    RPN& operator=(RPN const& rhs);

    void calculate(const std::string& expr);
};

#endif
