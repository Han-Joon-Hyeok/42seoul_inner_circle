#ifndef iter_HPP
#define iter_HPP

#include <iostream>
#include <string>

// Return nothing
template <typename T>
void iter(T* ptr, std::size_t length, void (*func)(T)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

template <typename T>
void iter(T* ptr, std::size_t length, void (*func)(T&)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

template <typename T>
void iter(T* ptr, std::size_t length, void (*func)(const T&)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// Return T : Argument is value type
template <typename T>
void iter(T* ptr, std::size_t length, T (*func)(T)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

template <typename T>
void iter(T* ptr, std::size_t length, const T (*func)(const T)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// Return T : Argument is reference type
template <typename T>
void iter(T* ptr, std::size_t length, T (*func)(T&)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

template <typename T>
void iter(T* ptr, std::size_t length, const T (*func)(const T&)) {
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// Test function template
template <typename T>
void printValue(T value) {
  std::cout << value << std::endl;
}

template <typename T>
void printValue(T& value) {
  std::cout << value << std::endl;
}

template <typename T>
void printValue(const T& value) {
  std::cout << value << std::endl;
}

// instantiated function template
template void printValue(const std::string& value);

#endif
