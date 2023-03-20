#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack(void);
  MutantStack(const MutantStack& src);
  ~MutantStack(void);
  MutantStack& operator=(MutantStack const& rhs);

  // Iterator
  typedef typename MutantStack<T>::stack::container_type::iterator        iterator;
  typedef typename MutantStack<T>::stack::container_type::const_iterator  const_iterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

#include "MutantStack.tpp"

#endif
