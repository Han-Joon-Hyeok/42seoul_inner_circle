#ifndef Array_HPP
#define Array_HPP

#include <stdexcept>

template <class T>
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

  void setValue(const T& value, const unsigned int index);
  unsigned int size(void) const;

  const T& operator[](const unsigned int index) const;
};

#include "Array.tpp"

#endif
