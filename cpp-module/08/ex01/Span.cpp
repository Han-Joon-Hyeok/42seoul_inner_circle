#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

class AbsoluteValue {
 public:
  int operator()(int x) const { return std::abs(x); }
};

Span::Span(unsigned int n) { this->max_size_ = n; }

// Span::Span(const Span& src)
// {
// }

Span::~Span(void) {}

// Span& Span::operator=(Span const& rhs)
// {
// 	if (this != &rhs)
// 	{
// 	}
// 	return *this;
// }

void Span::addNumber(unsigned int n) {
  if (this->max_size_ == this->set_.size()) {
    throw(Span::MaxSizeException());
  }
  this->set_.insert(n);
  std::cout << "Current size: " << this->set_.size() << std::endl;
}

unsigned int Span::shortestSpan(void) {
  if (this->set_.size() <= 1) {
    throw(Span::UnableToSpanException());
  }

  std::vector<unsigned int> copy_vec(this->set_.begin(), this->set_.end());
  std::vector<long long> diff_vec(this->set_.size());

  std::adjacent_difference(copy_vec.begin(), copy_vec.end(), diff_vec.begin());
  std::transform(diff_vec.begin(), diff_vec.end(), diff_vec.begin(),
                 AbsoluteValue());

  return (*(std::min_element(diff_vec.begin(), diff_vec.end())));
}

// unsigned int Span::longestSpan(void) {

// }

const char* Span::MaxSizeException::what() const throw() {
  return ("Can't add more elements.");
}

const char* Span::UnableToSpanException::what() const throw() {
  return ("Can't span because there is no element or only one element.");
}
