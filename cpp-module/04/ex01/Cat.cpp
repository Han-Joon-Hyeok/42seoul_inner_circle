#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  std::cout << "[Constructor] Default Cat created (type: " << getType() << ")"
            << std::endl;
  brain_ = new Brain();
  makeIdea("Hello Cat!");
}

Cat::~Cat(void) {
  std::cout << "[Destructor] Cat Destructor (type: " << getType() << ")"
            << std::endl;
  delete brain_;
}

Cat::Cat(const Cat& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

Cat& Cat::operator=(const Cat& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    delete this->brain_;
    this->brain_ = new Brain();
    *(this->brain_) = *(rhs.brain_);
  }
  return (*this);
}

void Cat::makeSound(void) const {
  std::cout << "[" << getType() << "] "
            << "Meow~" << std::endl;
}

void Cat::makeIdea(const std::string& idea) const {
  for (int idx = 0; idx < NUMBER_OF_IDEA; idx += 1) {
    std::string str("Cat idea " + std::to_string(idx) + ": " + idea);
    brain_->setIdea(idx, str);
  }
}

void Cat::displayIdea(void) const {
  for (int idx = 0; idx < NUMBER_OF_IDEA; idx += 1) {
    std::cout << brain_->getIdea(idx) << std::endl;
  }
}
