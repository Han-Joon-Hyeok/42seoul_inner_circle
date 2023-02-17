#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;

 public:
  Point(void);
  ~Point(void);
  Point(const Point &rhs);
  Point &operator=(const Point &rhs);

  Point(const float x, const float y);

  Fixed &getX(void);
  Fixed &getY(void);
};

#endif
