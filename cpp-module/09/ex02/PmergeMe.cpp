#include "PmergeMe.hpp"

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
  std::copy(this->list_.begin(), this->list_.end(),
            std::back_inserter(this->vector_));
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

std::vector<size_t> PmergeMe::getVector(void) { return (this->vector_); }
std::list<size_t> PmergeMe::getList(void) { return (this->list_); }

void PmergeMe::printResult(std::clock_t start, std::clock_t end,
                           const std::string& type) {
  double diff = (double)(end - start) / CLOCKS_PER_SEC;

  std::cout.precision(5);
  std::cout << std::fixed << "Time to process a range of   "
            << this->list_.size() << " elements with std::" << type << " : "
            << diff << " us" << std::endl;
}

const char* PmergeMe::InvalidInput::what(void) const throw() { return (""); }
