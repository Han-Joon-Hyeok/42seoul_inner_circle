#ifndef iter_HPP
#define iter_HPP

#include <iostream>
#include <string>

// Allow reference type argument
template <class T>
void iter(T* ptr, std::size_t length, void (*func)(T&)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// Ignore reference type argument
template <class T>
void iter(T* ptr, std::size_t length, void (*func)(T)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// Allow reference type argument
template <class T>
void print(T& value) {
  std::cout << value << std::endl;
}

// Ignore reference type argument
template <class T>
void print(T value) {
  std::cout << value << std::endl;
}

// instantiated function template
template void print(const std::string& value);

#endif
