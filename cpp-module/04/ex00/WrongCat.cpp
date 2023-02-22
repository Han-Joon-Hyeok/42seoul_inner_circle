#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "[Constructor] Default WrongCat created (type: " << getType()
            << ")" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "[Destructor] WrongCat Destructor (type: " << getType() << ")" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    this->type = rhs.getType();
  }
  return (*this);
}

void WrongCat::makeSound(void) const {
  std::cout << "[" << getType() << "] " << "Meow~" << std::endl;
}
