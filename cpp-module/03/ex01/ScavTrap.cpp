#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(100);
  std::cout << "[Constructor] Hello world, ScavTrap is: " << getName()
            << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "[Destructor] Bye world, ScavTrap is: " << getName()
            << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& rhs) { *this = rhs; }

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
  if (this != &rhs) {
    this->setName(rhs.getName());
  }
  return (*this);
}

void  ScavTrap::guardGate(void) {
  
}
