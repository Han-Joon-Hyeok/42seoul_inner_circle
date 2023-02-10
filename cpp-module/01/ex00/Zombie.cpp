#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie(void) { }

Zombie::Zombie(std::string name) {
  name_ = name;
}

Zombie::~Zombie(void) {
  std::cout << getName() << " is going to sleep... Grrrr" << std::endl;
}

std::string Zombie::getName(void) { return (name_); }

void Zombie::announce(void) {
  std::cout << getName() << ": "
            << "BraiiiiiiinnnzzzZ..." << std::endl;
}
