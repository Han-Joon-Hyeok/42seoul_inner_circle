#include "Zombie.hpp"

#include <iostream>

/* Constructor */
Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) { name_ = name; }

/* Desstructor */
Zombie::~Zombie(void) {
  std::cout << "[" << GREEN_TEXT << getIndex() << CUT_TEXT << "]" << getName()
            << " is going to sleep... Grrrr" << std::endl;
}

std::string Zombie::getName(void) { return (name_); }

void Zombie::setName(std::string name) { name_ = name; }

int Zombie::getIndex(void) { return (idx_); }

void Zombie::setIndex(int idx) { idx_ = idx; }

void Zombie::announce(void) {
  std::cout << "My index is: " << GREEN_TEXT << getIndex() << CUT_TEXT
            << std::endl;
  std::cout << getName() << ": "
            << "BraiiiiiiinnnzzzZ..." << std::endl
            << std::endl;
}
