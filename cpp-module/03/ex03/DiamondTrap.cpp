#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap() {
  this->hit_points_ = FragTrap::hit_points_;
  this->energy_points_ = ScavTrap::energy_points_;
  this->attack_damage_ = FragTrap::attack_damage_;
  this->name_ = "defaultDT";
  std::cout << "[Constructor] Hello world, DiamondTrap is: " << this->name_
            << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
  this->hit_points_ = FragTrap::hit_points_;
  this->energy_points_ = ScavTrap::energy_points_;
  this->attack_damage_ = FragTrap::attack_damage_;
  this->name_ = name;
  std::cout << "[Constructor] Hello world, DiamondTrap is: " << this->name_
            << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "[Destructor] Bye world, DiamondTrap is: " << this->name_
            << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) { *this = rhs; }

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
  if (this != &rhs) {
    this->setName(rhs.name_);
    this->setHitPoints(rhs.getHitPoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setAttackDamage(rhs.getAttackDamage());
  }
  return (*this);
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
  std::cout << "[DiamondTrap] ClapTrap: " << ClapTrap::name_
            << " DiamondTrap: " << this->name_ << std::endl;
}
