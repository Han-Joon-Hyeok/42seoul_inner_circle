#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
  std::cout << "[Constructor] Default WrongAnimal created (type: " << getType()
            << ")" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
  std::cout << "[Constructor] Typed WrongAnimal created (type: " << getType() << ")"
            << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "[Destructor] WrongAnimal Destructor (type: " << getType() << ")" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    this->type = rhs.getType();
  }
  return (*this);
}

const std::string& WrongAnimal::getType(void) const { return (this->type); }

void WrongAnimal::makeSound(void) const {
  std::cout << "[" << getType() << "] " << "Grrr..." << std::endl;
}
