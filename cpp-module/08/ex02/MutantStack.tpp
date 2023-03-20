#ifndef MutantStack_TPP
#define MutantStack_TPP

template <typename T>
MutantStack<T>::MutantStack(void) { }

template <typename T>
MutantStack<T>::~MutantStack(void) { }

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) {
  *this = src;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> const& rhs) {
  if (this != &rhs) {
    *this = rhs;
  }
  return (*this);
}

template <typename T>
typename MutantStack<T>::stack::container_type::iterator MutantStack<T>::begin(void) {
  return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::stack::container_type::iterator MutantStack<T>::end(void) {
  return (this->c.end());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_iterator MutantStack<T>::begin(void) const {
  return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::stack::container_type::const_iterator MutantStack<T>::end(void) const {
  return (this->c.end());
}

#endif
