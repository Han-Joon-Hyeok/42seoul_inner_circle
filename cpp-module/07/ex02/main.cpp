#include <iostream>

#include "Array.hpp"

#define ARRAY_SIZE 5

int main(void) {
  // Error case: when n is negative value
  std::cout << std::string(50, '=') << std::endl;

  try {
    Array<int> int_arr(-1);   // invalid argument
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Error case: when index is out of range
  try {
    Array<std::string> str_arr(ARRAY_SIZE);
    std::cout << str_arr[ARRAY_SIZE] << std::endl;   // index is out of range
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Success case: subscript operator
  try {
    Array<std::string> str_arr(ARRAY_SIZE);
    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "HELLO idx: " + std::to_string(idx);
    }
    std::cout << str_arr[0] << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Success case: copy constructor
  try {
    Array<std::string> str_arr(ARRAY_SIZE);

    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "HELLO idx: " + std::to_string(idx);
    }

    Array<std::string> copy_arr(str_arr);

    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      std::cout << copy_arr[idx] << std::endl;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  // Success case: copy assignment operator
  try {
    Array<std::string> str_arr(ARRAY_SIZE);
    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "HELLO idx: " + std::to_string(idx);
    }

    Array<std::string> copy_arr = str_arr;
    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      std::cout << copy_arr[idx] << std::endl;
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;
}
