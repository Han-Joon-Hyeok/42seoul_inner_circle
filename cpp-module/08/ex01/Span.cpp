#include "Span.hpp"

#include <iostream>

Span::Span(unsigned int n) : max_size_(n) {
  std::cout << "Successfully created vector" << std::endl;
  std::cout << "Max size is: " << n
            << " / Current size: " << vec_.size() << std::endl;

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
  if (this->getMaxSize() == vec_.size()) {
    throw(Span::MaxSizeException());
  }
  vec_.push_back(n);
  std::cout << "Current size: " << this->vec_.size() << std::endl;
}

unsigned int Span::getMaxSize(void) const { return (max_size_); }

// unsigned int Span::shortestSpan(void) {

// }

// unsigned int Span::longestSpan(void) {

// }

const char* Span::MaxSizeException::what() const throw() {
  return ("Can't add more elements.");
}
