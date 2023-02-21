#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
  setType("FragTrap");
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << "[Constructor] Hello world, FragTrap is: " << getName()
            << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  setType("FragTrap");
  setHitPoints(100);
  setEnergyPoints(100);
  setAttackDamage(30);
  std::cout << "[Constructor] Hello world, FragTrap is: " << getName()
            << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "[Destructor] Bye world, FragTrap is: " << getName()
            << std::endl;
}

FragTrap::FragTrap(const FragTrap& rhs) { *this = rhs; }

FragTrap& FragTrap::operator=(const FragTrap& rhs) {
  if (this != &rhs) {
    this->setName(rhs.getName());
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return (*this);
}

void FragTrap::highFiveGuys(void) {
  unsigned int current_energy_points = getEnergyPoints();
  unsigned int current_hit_points = getHitPoints();

  if (current_energy_points > 0 && current_hit_points > 0) {
    std::cout << "[FragTrap] " << getName() << " want to high five."
              << std::endl;
  } else {
    std::cout
        << "[FragTrap] " << getName()
        << " can't high five because of not enough hit points or energy points"
        << " (current energy point: " << current_energy_points << ","
        << " current hit point: " << current_hit_points << ")" << std::endl;
  }
}
