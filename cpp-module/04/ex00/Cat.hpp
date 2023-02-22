#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat: public Animal {
 public:
	Cat(void);
	~Cat(void);
  Cat(const Cat& rhs);
  Cat& operator=(const Cat& rhs);

  virtual void makeSound(void) const;
};

#endif
