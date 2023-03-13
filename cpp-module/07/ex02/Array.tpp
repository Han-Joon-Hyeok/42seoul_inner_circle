#include "Array.hpp"

// Default constructor
template <class T>
Array<T>::Array(void) {
  try {
    array_ = new T[0]();
    size_ = 0;
  } catch (const std::bad_alloc& ba) {
    std::cerr << "bad alloc occurs" << ba.what() << '\n';
  }
};

// Custom constructor
template <class T>
Array<T>::Array(unsigned int n) {
  if (static_cast<int>(n) < 0) {
    throw(std::invalid_argument("Negative value is unavailable"));
  }
  try {
    array_ = new T[n]();
    size_ = n;
  } catch (const std::bad_alloc& ba) {
    std::cerr << "bad alloc occurs" << ba.what() << '\n';
  }
};

// Destructor
template <class T>
Array<T>::~Array(void) {
  delete[] this->array_;
};

// Copy constructor
template <class T>
Array<T>::Array(const Array<T>& src) {
  *this = src;
};

// Copy assignment
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
  if (this != &rhs) {
    delete[] this->array_;
    try {
      this->array_ = new T[rhs.size()]();
      size_ = rhs.size();
      for (unsigned int index = 0; index < rhs.size(); index += 1) {
        this->setValue(rhs[index], index);
      }
    } catch (const std::bad_alloc& ba) {
      std::cerr << "bad alloc occurs" << ba.what() << '\n';
    }
  }
  return (*this);
};

template <class T>
void Array<T>::setValue(const T& value, const unsigned int index) {
  if (static_cast<int>(index) < 0) {
    throw(std::invalid_argument("Negative value is unavailable"));
  }
  if (index >= this->size()) {
    throw(std::out_of_range("Index is out of range"));
  }
  this->array_[index] = value;
};

template <class T>
unsigned int Array<T>::size(void) const {
  return (this->size_);
};

template <class T>
const T& Array<T>::operator[](const unsigned int index) const {
  if (index >= this->size()) {
    throw(std::out_of_range("Index is out of range"));
  }
  return (array_[index]);
};
