#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
 public:
	WrongCat(void);
	~WrongCat(void);
  WrongCat(const WrongCat& rhs);
  WrongCat& operator=(const WrongCat& rhs);

  void makeSound(void) const;
};

#endif
