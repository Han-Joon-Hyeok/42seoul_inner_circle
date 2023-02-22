#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[Constructor] Default Dog created (type: " << getType() << ")"
            << std::endl;
  brain_ = new Brain();
  makeIdea("Hello Dog!");
}

Dog::~Dog(void) {
  std::cout << "[Destructor] Dog Destructor (type: " << getType() << ")"
            << std::endl;
  delete brain_;
}

Dog::Dog(const Dog& rhs) {
  std::cout << "[Copy constructor] I will copy: " << rhs.getType() << std::endl;
  *this = rhs;
}

Dog& Dog::operator=(const Dog& rhs) {
  std::cout << "[Copy assignment operator] I will copy: " << rhs.getType()
            << std::endl;
  if (this != &rhs) {
    delete this->brain_;
    this->brain_ = new Brain();
    *(this->brain_) = *(rhs.brain_);
  }
  return (*this);
}

void Dog::makeSound(void) const {
  std::cout << "[" << getType() << "] "
            << "Bowwow!" << std::endl;
}

void Dog::makeIdea(const std::string& idea) const {
  for (int idx = 0; idx < NUMBER_OF_IDEA; idx += 1) {
    std::string str("Dog idea " + std::to_string(idx) + ": " + idea);
    brain_->setIdea(idx, str);
  }
}

void Dog::displayIdea(void) const {
  for (int idx = 0; idx < NUMBER_OF_IDEA; idx += 1) {
    std::cout << brain_->getIdea(idx) << std::endl;
  }
}
