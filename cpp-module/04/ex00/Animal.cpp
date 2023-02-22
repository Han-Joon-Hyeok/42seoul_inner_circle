#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) : type("Animal") {
  std::cout << "[Constructor] Default Animal created (type: " << getType()
            << ")" << std::endl;
}

Animal::Animal(const std::string& type) : type(type) {
  std::cout << "[Constructor] Typed Animal created (type: " << getType() << ")"
            << std::endl;
}

Animal::~Animal(void) {
  std::cout << "[Destructor] Animal Destructor (type: " << getType() << ")" << std::endl;
}

Animal::Animal(const Animal& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

Animal& Animal::operator=(const Animal& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    this->type = rhs.getType();
  }
  return (*this);
}

const std::string& Animal::getType(void) const { return (this->type); }

void Animal::makeSound(void) const {
  std::cout << "[" << getType() << "] " << "Grrr..." << std::endl;
}
