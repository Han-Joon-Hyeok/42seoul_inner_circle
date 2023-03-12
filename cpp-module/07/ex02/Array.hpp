#ifndef Array_HPP
#define Array_HPP

template <class T>
class Array {
 private:
  unsigned int size_;
  unsigned int total_size_;
  T* array_;

 public:
  Array(void) {
    try {
      array_ = new T[0]();
      size_ = 0;
      total_size_ = 0;
    } catch (const std::bad_alloc& ba) {
      std::cerr << "bad alloc occurs" << ba.what() << '\n';
    }
  };

  Array(unsigned int n) {
    try {
      array_ = new T[n]();
    } catch (const std::bad_alloc& ba) {
      std::cerr << "bad alloc occurs" << ba.what() << '\n';
    }
  };

  Array(const T& src) { *this = src; };
  virtual ~Array(void) { delete[] array_; }
  T& operator=(T const& rhs) {
    if (this != &rhs) {
    }
    return (*this);
  }

  T& getArray(void) const { return (array_); };
  const unsigned int size(void) const { return (size_); };
  const T& operator[](const unsigned int index) const {
    if (index >= this->size()) {
    }
    return (array_[idx]);
  }
};

#endif
