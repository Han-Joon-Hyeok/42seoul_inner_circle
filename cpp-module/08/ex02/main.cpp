#include <iostream>
#include <stack>
#include <list>

#include "MutantStack.hpp"

int main(void) {
  {
    std::cout << "===========MutantStack version===========" << std::endl;

    MutantStack<int> mstack;

    mstack.push(0);
    mstack.push(1);

    std::cout << "Stack top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Stack current size: " << mstack.size() << std::endl;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);

    MutantStack<int>::iterator it = mstack.begin();   // Start from stack bottom
    MutantStack<int>::iterator ite = mstack.end();    // Start from stack top

    ++it;
    --it;

    std::cout << "===========Iterating stack elements===========" << std::endl;

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "===========Iterating copied stack elements===========" << std::endl;
    std::stack<int> s(mstack);

    while (s.empty() == false) {
      std::cout << s.top() << std::endl;
      s.pop();
    }
  }
  {
    std::cout << "===========std::list version===========" << std::endl;

    std::list<int> list;

    list.push_back(0);
    list.push_back(1);

    std::cout << "List back: " << list.back() << std::endl;

    list.pop_back();

    std::cout << "List current size: " << list.size() << std::endl;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();

    ++it;
    --it;

    std::cout << "===========Iterating stack elements===========" << std::endl;

    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }

    std::cout << "===========Iterating copied list elements===========" << std::endl;

    std::list<int> l(list);

    while (l.size() > 0) {
      std::cout << l.back() << std::endl;
      l.pop_back();
    }
  }
}
