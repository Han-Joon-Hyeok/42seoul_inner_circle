#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  std::cout << "[Constructor] Default Cat created (type: " << getType()
            << ")" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "[Destructor] Cat Destructor (type: " << getType() << ")" << std::endl;
}

Cat::Cat(const Cat& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

Cat& Cat::operator=(const Cat& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    this->type = rhs.getType();
  }
  return (*this);
}

void Cat::makeSound(void) const {
  std::cout << "[" << getType() << "] " << "Meow~" << std::endl;
}
