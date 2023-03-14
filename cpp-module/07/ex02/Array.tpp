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
  this->array_ = NULL;
  size_ = 0;
};

// Copy constructor
template <class T>
Array<T>::Array(const Array<T>& src) : size_(src.size_) {
  try {
    this->array_ = new T[size_]();
    for (unsigned int idx = 0; idx < size_; idx += 1) {
      array_[idx] = T(src.array_[idx]);
    }
  } catch(std::bad_alloc &ba) {
    std::cout << ba.what() << std::endl;
  }
};

// Copy assignment
template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
  if (this != &rhs) {
    delete[] this->array_;
    try {
      size_ = rhs.size_;
      this->array_ = new T[size_]();
      for (unsigned int idx = 0; idx < size_; idx += 1) {
        this->array_[idx] = T(rhs[idx]);
      }
    } catch (const std::bad_alloc& ba) {
      std::cerr << "bad alloc occurs" << ba.what() << '\n';
    }
  }
  return (*this);
};

template <class T>
unsigned int Array<T>::size(void) const {
  return (this->size_);
};

template <class T>
T& Array<T>::operator[](const unsigned int index) const {
  if (index >= this->size()) {
    throw(std::out_of_range("Index is out of range"));
  }
  return (array_[index]);
};
