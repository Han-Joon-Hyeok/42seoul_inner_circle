#include <iostream>

#include "Fixed.hpp"

Fixed::Fixed(void): value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &rhs) {
  std::cout << "Copy constructor called" << std::endl;
  *this = rhs;
 }

 Fixed& Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    value_ = rhs.getRawBits();
  }
  return (*this);
 }


int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (value_);
}

void Fixed::setRawBits(int const raw) { value_ = raw; }
