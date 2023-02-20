#include "Point.hpp"

Point::Point(void) : x_(0), y_(0) {}

Point::~Point(void) {}

Point::Point(const Point& rhs) : x_(rhs.getX()), y_(rhs.getY()) {}

Point& Point::operator=(const Point& rhs) {
  if (this != &rhs) {
    const_cast<Fixed&>(x_) = rhs.getX();
    const_cast<Fixed&>(y_) = rhs.getY();
  }
  return (*this);
}

Point::Point(const Fixed x, const Fixed y) : x_(x), y_(y) {}

Fixed Point::getX(void) const { return (x_); }

Fixed Point::getY(void) const { return (y_); }
