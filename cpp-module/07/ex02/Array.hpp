#ifndef Array_HPP
#define Array_HPP

#include <stdexcept>

template <typename T>
class Array {
 private:
  unsigned int size_;
  T* array_;

 public:
  Array(void);
  Array(unsigned int n);
  ~Array(void);
  Array(const Array<T>& src);
  Array<T>& operator=(Array<T> const& rhs);

  unsigned int size(void) const;

  T& operator[](const unsigned int index) const;
};

#include "Array.tpp"

#endif
