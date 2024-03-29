#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
  std::cout << "[Constructor] Hello world, ScavTrap is: " << getName()
            << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  setHitPoints(100);
  setEnergyPoints(50);
  setAttackDamage(20);
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
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return (*this);
}

void ScavTrap::guardGate(void) {
  unsigned int current_energy_points = getEnergyPoints();
  unsigned int current_hit_points = getHitPoints();

  if (current_energy_points > 0 && current_hit_points > 0) {
    std::cout << "[ScavTrap] " << getName() << " is in Gate keeper mode."
              << std::endl;
  } else {
    std::cout << "[ScavTrap] " << getName()
              << " can't be Gate keeper mode because of not enough hit points "
                 "or energy points"
              << " (current energy point: " << current_energy_points << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  }
}

void ScavTrap::attack(const std::string& target) {
  unsigned int current_energy_points = getEnergyPoints();
  unsigned int current_hit_points = getHitPoints();

  if (current_energy_points > 0 && current_hit_points > 0) {
    setEnergyPoints(current_energy_points - 1);
    std::cout << "[ScavTrap] " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!"
              << "(current energy point: " << current_energy_points - 1 << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  } else {
    std::cout << "[ScavTrap] " << getName() << " can't attack " << target
              << ", because of not enough energy point or hit points."
              << "(current energy point: " << current_energy_points << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  }
}
