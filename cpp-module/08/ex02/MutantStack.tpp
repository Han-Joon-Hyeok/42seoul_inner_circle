#ifndef MutantStack_TPP
#define MutantStack_TPP

// #include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) { }

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void) { }

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T>& src) : c(src.c) { }

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(
    MutantStack<T> const& rhs) {
  if (this != &rhs) {
    this->c = rhs.c;
  }
  return (*this);
}

template <typename T, typename Container>
bool MutantStack<T, Container>::empty(void) const {
  return (c.empty());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::size_type MutantStack<T, Container>::size()
    const {
  return (c.size());
}

template <typename T, typename Container>
typename MutantStack<T, Container>::value_type& MutantStack<T, Container>::top() {
  return (c.back());
}

template <typename T, typename Container>
const T& MutantStack<T, Container>::top() const {
  return (c.back());
}

template <typename T, typename Container>
void MutantStack<T, Container>::push(const T& value) {
  c.push_back(value);
}

template <typename T, typename Container>
void MutantStack<T, Container>::pop(void) {
  c.pop_back();
}

#include "MutantStack.tpp"

#endif
