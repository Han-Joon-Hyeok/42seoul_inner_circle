#include "Span.hpp"

#include <algorithm>
#include <iostream>

Span::Span(unsigned int n) {
  try {
    vec_.reserve(n);
    std::cout << "Max size is: " << vec_.capacity()
              << " / Current size: " << vec_.size() << std::endl;
  } catch (std::length_error& le) {
    std::cout << le.what() << std::endl;
  }
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
  if (vec_.capacity() == vec_.size()) {
    throw(Span::MaxSizeException());
  }
  vec_.push_back(n);
  std::cout << "Current size: " << this->vec_.size() << std::endl;
}

// unsigned int Span::shortestSpan(void) {
//   if (isAbleToSpan() == false) {
//     throw(Span::UnableToSpanException());
//   }
//   return (1);
// }

bool Span::isAbleToSpan(void) const {
  if (vec_.size() == 0 || vec_.size() == 1) {
    return (false);
  }
  return (true);
}

// unsigned int Span::longestSpan(void) {

// }

const char* Span::MaxSizeException::what() const throw() {
  return ("Can't add more elements.");
}

const char* Span::UnableToSpanException::what() const throw() {
  return ("Can't span because there is no element or only one element.");
}
