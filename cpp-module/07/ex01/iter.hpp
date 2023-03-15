#ifndef iter_HPP
#define iter_HPP

#include <iostream>
#include <string>

// Non-const T pointer
// Function pointer get an argument as non-const reference
template <typename T>
void iter(T* ptr, std::size_t length, void (*func)(T)) {
  if (ptr == NULL || func == NULL) {
    return ;
  }
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// const T pointer
// Function pointer get an argument as const reference
template <typename T>
void iter(const T* ptr, std::size_t length, void (*func)(const T&)) {
  if (ptr == NULL || func == NULL) {
    return ;
  }
  for (std::size_t idx = 0; idx < length; idx += 1) {
    func(ptr[idx]);
  }
}

// Test function template
template <typename T>
void printValue(const T& value) {
  std::cout << value << std::endl;
}

#endif
