#ifndef MutantStack_TPP
#define MutantStack_TPP

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T>::MutantStack(const MutantStack<T>& src) {

}

template <typename T, typename Container>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& rhs) {

}

template <typename T, typename Container>
bool  MutantStack<T>::empty(void) const {
  return (c.empty());
}

size_type size(void) const;
value_type& top(void);
const T& top(void) const;
void push(const T& value);

#include "MutantStack.tpp"

#endif
