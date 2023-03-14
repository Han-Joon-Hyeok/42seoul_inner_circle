#include <iostream>

#include "iter.hpp"

#define ARRAY_SIZE 10

void printInt(int num) { std::cout << "num: " << num << std::endl; }

int main(void) {
  std::cout << std::string(50, '=') << std::endl;

  {
    int num_arr[ARRAY_SIZE];

    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      num_arr[idx] = idx;
    }

    ::iter(num_arr, sizeof(num_arr) / sizeof(*num_arr), printInt);
  }

  std::cout << std::string(50, '=') << std::endl;

  {
    std::string str_arr[ARRAY_SIZE];

    for (int idx = 0; idx < ARRAY_SIZE; idx += 1) {
      str_arr[idx] = "hello " + std::to_string(idx);
    }

    ::iter(str_arr, ARRAY_SIZE, ::printValue<std::string&>);
  }
}
