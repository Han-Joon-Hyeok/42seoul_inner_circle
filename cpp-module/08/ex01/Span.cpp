#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

Span::Span(unsigned int n) { this->max_size_ = n; }

Span::Span(const Span& src)
    : max_size_(src.max_size_), set_(src.set_.begin(), src.set_.end()) {}

Span::~Span(void) {}

Span& Span::operator=(Span const& rhs) {
  if (this != &rhs) {
    this->max_size_ = rhs.max_size_;
    this->set_ = rhs.set_;
  }
  return *this;
}

void Span::addNumber(unsigned int n) {
  if (this->max_size_ == this->set_.size()) {
    throw(Span::MaxSizeException());
  }
  this->set_.insert(n);
}

unsigned int Span::shortestSpan(void) {
  if (this->set_.size() <= 1) {
    throw(Span::UnableToSpanException());
  }

  std::vector<unsigned int> copy_vec(this->set_.begin(), this->set_.end());
  std::vector<long long> diff_vec(this->set_.size());

  std::adjacent_difference(copy_vec.begin(), copy_vec.end(), diff_vec.begin());

  return (*(std::min_element(diff_vec.begin() + 1, diff_vec.end())));
}

unsigned int Span::longestSpan(void) {
  if (this->set_.size() <= 1) {
    throw(Span::UnableToSpanException());
  }

  std::set<unsigned int>::iterator begin = this->set_.begin();
  std::set<unsigned int>::iterator end = this->set_.end();

  return (*(--end) - *(begin));
}

const char* Span::MaxSizeException::what() const throw() {
  return ("Can't add more elements.");
}

const char* Span::UnableToSpanException::what() const throw() {
  return ("Can't span because there is no element or only one element.");
}
