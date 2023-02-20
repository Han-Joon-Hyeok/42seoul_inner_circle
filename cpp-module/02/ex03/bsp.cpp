#include "Point.hpp"

bool isPositive(Point const p1, Point const p2, Point const target) {
	Fixed	x1 = p1.getX();
	Fixed	y1 = p1.getY();
	Fixed	x2 = p2.getX();
	Fixed	y2 = p2.getY();
	Fixed x = target.getX();
	Fixed y = target.getY();

	if ((y - y1) * (x2 - x1) - (y2 - y1) * (x - x1) >= 0) {
		return (true);
	}
	return (false);
}

bool bsp(Point const a, Point const b, Point const c, Point const target) {
  if (isPositive(a, b, target) && isPositive(b, c, target) &&
      isPositive(c, a, target)) {
    return (true);
  }
  return (false);
}
