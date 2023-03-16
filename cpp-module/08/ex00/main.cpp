#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

#define CONTAINER_SIZE 5

int main(void) {
  std::vector<int> vec;
  std::deque<int> deque;
  std::list<int> lst;

  for (int idx = 0; idx < CONTAINER_SIZE; idx += 1) {
    vec.push_back(idx);
    deque.push_back(idx);
    lst.push_back(idx);
  }

  try {
    std::vector<int>::iterator iter = ::easyfind(vec, CONTAINER_SIZE - 4);
    std::cout << "Find value is : " << *iter << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::deque<int>::iterator iter = ::easyfind(deque, CONTAINER_SIZE - 2);
    std::cout << "Find value is : " << *iter << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    std::list<int>::iterator iter = ::easyfind(lst, CONTAINER_SIZE + 100);
    std::cout << "Find value is : " << *iter << std::endl;
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    const std::vector<int> c_vec(4);
    ::easyfind(c_vec, 3);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
}
