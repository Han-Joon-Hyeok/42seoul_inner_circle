#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n) : size_(n)
{
	std::cout << "Current capacity: " << vec_.capacity() << std::endl;
	std::cout << "Current size: " << vec_.size() << std::endl;
}

// Span::Span(const Span& src)
// {
// }

Span::~Span(void)
{
}

// Span& Span::operator=(Span const& rhs)
// {
// 	if (this != &rhs)
// 	{
// 	}
// 	return *this;
// }

// void Span::addNumber(unsigned int n) {

// }

// unsigned int Span::shortestSpan(void) {

// }

// unsigned int Span::longestSpan(void) {

// }

