#include "Brain.hpp"

#include <iostream>

Brain::Brain(void) {
  std::cout << "[Constructor] Default Brain created" << std::endl;
}

Brain::~Brain(void) {
  std::cout << "[Destructor] Brain Destructor" << std::endl;
}

Brain::Brain(const Brain& rhs) {
  std::cout << "[Copy constructor] Brain" << std::endl;
  *this = rhs;
}

Brain& Brain::operator=(const Brain& rhs) {
  std::cout << "[Copy assignment operator] Brain" << std::endl;
  if (this != &rhs) {
    for (int idx = 0; idx < NUMBER_OF_IDEA; idx += 1) {
      setIdea(idx, rhs.getIdea(idx));
    }
  }
  return (*this);
}

const std::string& Brain::getIdea(int idx) const { return (ideas[idx]); }

void Brain::setIdea(int idx, const std::string& idea) { ideas[idx] = idea; }
