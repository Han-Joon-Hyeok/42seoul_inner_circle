#include "PmergeMe.hpp"

#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe(int argc, char** argv) {
  long long converted = 0;
  char* stop = NULL;

  for (int idx = 1; idx < argc; idx += 1) {
    converted = std::strtol(argv[idx], &stop, 10);
    if (argv[idx] == stop || *stop != '\0') {
      std::cout << "Error: invalid input => " << argv[idx] << std::endl;
      throw(PmergeMe::InvalidInput());
    }
    this->list_.push_back(converted);
  }

  if (hasDuplicatedNumber(this->list_) == true) {
    throw(PmergeMe::InvalidInput());
  }
}

PmergeMe::PmergeMe(const PmergeMe& src)
    : vector_(src.vector_), list_(src.list_) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

bool PmergeMe::hasDuplicatedNumber(std::list<ssize_t> list) {
  std::list<ssize_t>::iterator it = list.begin();

  for (; it != list.end(); ++it) {
    std::list<ssize_t>::iterator next = std::next(it);
    for (; next != list.end(); ++next) {
      if (*it == *next) {
        std::cout << "Error: found duplicated number => " << *it << std::endl;
        return (true);
      }
    }
  }

  return (false);
}

const char* PmergeMe::InvalidInput::what(void) const throw() { return (""); }
