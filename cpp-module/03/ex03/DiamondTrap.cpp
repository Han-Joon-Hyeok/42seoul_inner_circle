#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap() {
  setType("DiamondTrap");
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(30);
  std::cout << "[Constructor] Hello world, DiamondTrap is: " << getName()
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
  setType("DiamondTrap");
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(30);
  std::cout << "[Constructor] Hello world, DiamondTrap is: " << getName()
            << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "[Destructor] Bye world, DiamondTrap is: " << getName()
            << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) { *this = rhs; }

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return (*this);
}

void DiamondTrap::attack(std::string target) { ScavTrap::attack(target); }

void DiamondTrap::whoAmI(void) {
  std::cout << "[DiamondTrap] Hello, I am DiamondTrap: " << getName()
            << std::endl;
}
