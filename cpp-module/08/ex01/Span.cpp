#include "Span.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

Span::Span(unsigned int n) {
  this->max_size_ = n;
}

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
  set_.insert(n);
  std::cout << "Current size: " << this->set_.size() << std::endl;
}

unsigned int Span::shortestSpan(void) {
  if (this->set_.size() <= 1) {
    throw(Span::UnableToSpanException());
  }

  return (1);
}

// unsigned int Span::longestSpan(void) {

// }

const char* Span::MaxSizeException::what() const throw() {
  return ("Can't add more elements.");
}

const char* Span::UnableToSpanException::what() const throw() {
  return ("Can't span because there is no element or only one element.");
}
