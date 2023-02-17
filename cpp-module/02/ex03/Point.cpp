#include "Point.hpp"

#include <cmath>
#include <iostream>

Point::Point(void) : x_(0), y_(0) {}

Point::~Point(void) {}

Point::Point(const Point& rhs) { *this = rhs; }

Point& Point::operator=(const Point& rhs) {
  if (this != &rhs) {
    x_ = rhs.getX();
    y_ = rhs.getY();
  }
  return (*this);
}

Fixed& Point::getX(void) { return (x_); }

Fixed& Point::getY(void) { return (y_); }
