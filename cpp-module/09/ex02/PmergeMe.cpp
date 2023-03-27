#include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>

PmergeMe::PmergeMe(int argc, char** argv) {
  long long converted = 0;
  char* stop = NULL;

  for (int idx = 1; idx < argc; idx += 1) {
    converted = std::strtol(argv[idx], &stop, 10);
    if (argv[idx] == stop || *stop != '\0') {
      std::cout << "Error: invalid input => " << argv[idx] << std::endl;
      throw(PmergeMe::InvalidInput());
    }
    if (converted < 0) {
      std::cout << "Error: can't get negative value => " << converted
                << std::endl;
      throw(PmergeMe::InvalidInput());
    }
    this->list_.push_back(converted);
  }

  this->threshold_ = this->list_.size() / 3;

  this->vector_.reserve(this->list_.size());
  std::copy(this->list_.begin(), this->list_.end(), std::back_inserter(this->vector_));
}

PmergeMe::PmergeMe(const PmergeMe& src)
    : vector_(src.vector_), list_(src.list_) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe& PmergeMe::operator=(PmergeMe const& rhs) {
  if (this != &rhs) {
    this->vector_ = rhs.vector_;
    this->list_ = rhs.list_;
  }
  return *this;
}

void PmergeMe::recursiveListSort(std::list<size_t>::iterator first,
                                 std::list<size_t>::iterator last) {
  if (std::distance(first, last) <= this->threshold_) {
    insertion_sort(first, last);
    return;
  }

  std::list<size_t>::iterator middle = first;
  std::advance(middle, std::distance(first, last) / 2);

  recursiveListSort(first, middle);
  recursiveListSort(middle, last);

  std::inplace_merge(first, middle, last);
}

void PmergeMe::listMergeInsertionSort(void) {
  recursiveListSort(this->list_.begin(), this->list_.end());
}


void PmergeMe::recursiveVectorSort(std::vector<size_t>::iterator first,
                                 std::vector<size_t>::iterator last) {
  if (std::distance(first, last) < this->threshold_) {
    insertion_sort(first, last);
    return;
  }

  std::vector<size_t>::iterator middle = first;
  std::advance(middle, std::distance(first, last) / 2);

  recursiveVectorSort(first, middle);
  recursiveVectorSort(middle, last);

  std::merge(first, middle, middle, last, std::inserter(this->vector_, this->vector_.begin()));
  std::copy(this->vector_.begin(), this->vector_.end(), first);
}

void PmergeMe::vectorMergeInsertionSort(void) {
  recursiveVectorSort(this->vector_.begin(), this->vector_.end());
}

std::string PmergeMe::showVector(void) {
  std::vector<size_t>::iterator it = this->vector_.begin();
  std::string result;
  for (; it != this->vector_.end(); ++it) {
    result += std::to_string(*it) + " ";
  }
  return (result);
}

std::string PmergeMe::showList(void) {
  std::list<size_t>::iterator it = this->list_.begin();
  std::string result;
  for (; it != this->list_.end(); ++it) {
    result += std::to_string(*it) + " ";
  }
  return (result);
}

void PmergeMe::printResult(std::clock_t start, std::clock_t end,
                           const std::string& type) {
  double diff = (double)(end - start) / CLOCKS_PER_SEC;

  std::cout.precision(5);
  std::cout << std::fixed << "Time to process a range of   "
            << this->list_.size() << " elements with std::" << type << " : "
            << diff << " us" << std::endl;
}

const char* PmergeMe::InvalidInput::what(void) const throw() { return (""); }
