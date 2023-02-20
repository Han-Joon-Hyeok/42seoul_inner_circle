#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(void): raw_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
  std::cout << this->toFloat() << std::endl;
}

Fixed::Fixed(const Fixed &rhs) {
  std::cout << "Copy constructor called" << std::endl;
  *this = rhs;
}

Fixed& Fixed::operator=(const Fixed &rhs) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs) {
    raw_ = rhs.getRawBits();
  }
  return (*this);
}

Fixed::Fixed(const int raw) {
  std::cout << "Int constructor called" << std::endl;
  setRawBits(raw << bits_);
}

Fixed::Fixed(const float raw) {
  std::cout << "Float constructor called" << std::endl;
  setRawBits(roundf(raw * (1 << bits_)));
}

float Fixed::toFloat(void) const {
  return (((float)getRawBits() / (1 << bits_)));
}

int Fixed::toInt(void) const {
  return (getRawBits() >> bits_);
}

int Fixed::getRawBits(void) const {
  return (raw_);
}

void Fixed::setRawBits(int const raw) { raw_ = raw; }

std::ostream& operator<<(std::ostream &out, const Fixed& rhs) {
  out << rhs.toFloat();
  return (out);
}
