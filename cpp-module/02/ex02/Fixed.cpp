#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : raw_(0) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed& rhs) { *this = rhs; }

Fixed& Fixed::operator=(const Fixed& rhs) {
  if (this != &rhs) {
    raw_ = rhs.getRawBits();
  }
  return (*this);
}

Fixed::Fixed(const int raw) { setRawBits(raw << bits_); }

Fixed::Fixed(const float raw) { setRawBits(roundf(raw * (1 << bits_))); }

float Fixed::toFloat(void) const {
  return (((float)getRawBits() / (1 << bits_)));
}

int Fixed::toInt(void) const { return (getRawBits() >> bits_); }

int Fixed::getRawBits(void) const { return (raw_); }

void Fixed::setRawBits(int const raw) { raw_ = raw; }

std::ostream& operator<<(std::ostream& out, const Fixed& rhs) {
  out << rhs.toFloat();
  return (out);
}

Fixed& Fixed::operator++(void) {
  setRawBits(getRawBits() + 1);
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed prev(this->toFloat());

  setRawBits(getRawBits() + 1);
  return (prev);
}
