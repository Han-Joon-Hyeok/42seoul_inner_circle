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

  // if (hasDuplicatedNumber(this->list_) == true) {
  //   throw(PmergeMe::InvalidInput());
  // }

  this->threshold_ = this->list_.size() / 3;

  this->vector_.reserve(this->list_.size());
  std::copy(this->list_.begin(), this->list_.end(), this->vector_.begin());
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

bool PmergeMe::hasDuplicatedNumber(std::list<size_t> list) {
  std::list<size_t>::iterator it = list.begin();

  for (; it != list.end(); ++it) {
    std::list<size_t>::iterator next = std::next(it);
    for (; next != list.end(); ++next) {
      if (*it == *next) {
        std::cout << "Error: found duplicated number => " << *it << std::endl;
        return (true);
      }
    }
  }

  return (false);
}

void PmergeMe::printResult(std::clock_t start, std::clock_t end,
                           const std::string& type) {
  double diff = (double)(end - start) / CLOCKS_PER_SEC;

  std::cout.precision(5);
  std::cout << std::fixed << "Time to process a range of   "
            << this->list_.size() << " elements with std::" << type << " : "
            << diff << " us" << std::endl;
}

std::list<size_t>::const_iterator PmergeMe::getListIterator(void) const {
  return (this->list_.begin());
}

std::list<size_t>::const_iterator PmergeMe::getListEndIterator(void) const {
  return (this->list_.end());
}

const char* PmergeMe::InvalidInput::what(void) const throw() { return (""); }

std::ostream& operator<<(std::ostream& out, const PmergeMe& rhs) {
  std::list<size_t>::const_iterator it = rhs.getListIterator();
  std::list<size_t>::const_iterator ite = rhs.getListEndIterator();

  for (; it != ite; ++it) {
    out << *it << " ";
  }

  return (out);
}
