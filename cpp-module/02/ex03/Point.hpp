#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
 private:
  Fixed const x_;
  Fixed const y_;

 public:
  Point(void);
  ~Point(void);
  Point(const Point &rhs);
  Point &operator=(const Point &rhs);

  Point(const Fixed x, const Fixed y);

  Fixed getX(void) const;
  Fixed getY(void) const;
};

bool  bsp(Point const a, Point const b, Point const c, Point const point);

#endif
