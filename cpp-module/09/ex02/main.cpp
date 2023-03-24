#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc == 1) {
    std::cout << "Error: please enter at least one number. [./PmergeMe ...]"
              << std::endl;
    return (EXIT_FAILURE);
  }

  try
  {
    PmergeMe merge(argc, argv);
  }
  catch(const std::exception& e)
  {
    (void)e;
  }



  return (EXIT_SUCCESS);
}
