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
    std::clock_t start;
    std::clock_t end;
    std::list<size_t> list = merge.getList();
    std::vector<size_t> vector = merge.getVector();

    std::cout << "Before  : " << merge.showElements(list) << std::endl;
    start = std::clock();
    merge.mergeInsertionSort(list);
    end = std::clock();
    std::cout << "After   : " << merge.showElements(list) << std::endl;
    merge.printResult(start, end, "list");

    start = std::clock();
    merge.mergeInsertionSort(vector);
    end = std::clock();
    merge.printResult(start, end, "vector");
  }
  catch(const std::exception& e)
  {
    (void)e;
  }



  return (EXIT_SUCCESS);
}
