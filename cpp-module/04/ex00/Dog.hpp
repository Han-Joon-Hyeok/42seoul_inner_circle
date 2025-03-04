#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "Animal.hpp"

class Dog: public Animal {
 public:
	Dog(void);
	~Dog(void);
  Dog(const Dog& rhs);
  Dog& operator=(const Dog& rhs);

  virtual void makeSound(void) const;
};

#endif
