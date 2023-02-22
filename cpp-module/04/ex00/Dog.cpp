#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[Constructor] Default Dog created (type: " << getType()
            << ")" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "[Destructor] Dog Destructor (type: " << getType() << ")" << std::endl;
}

Dog::Dog(const Dog& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

Dog& Dog::operator=(const Dog& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    this->type = rhs.getType();
  }
  return (*this);
}

void Dog::makeSound(void) const {
  std::cout << "[" << getType() << "] " << "Bowwow!" << std::endl;
}
