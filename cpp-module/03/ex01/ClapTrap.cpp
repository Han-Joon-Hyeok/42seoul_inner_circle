#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(void)
    : type_("ClapTrap"),
      name_(""),
      hit_points_(10),
      energy_points_(10),
      attack_damage_(0) {
  std::cout << "[Constructor] Hello world, my ClapTrap is: " << getName()
            << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : type_("ClapTrap"),
      name_(name),
      hit_points_(10),
      energy_points_(10),
      attack_damage_(0) {
  std::cout << "[Constructor] Hello world, my ClapTrap is: " << getName()
            << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "[Destructor] Bye world, my ClapTrap is: " << getName()
            << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs) {
  std::cout << "[Copy constructor] Hello world, my ClapTrap is: "
            << rhs.getName() << std::endl;
  *this = rhs;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
  std::cout << "[Copy assignment operator] Hello world, my ClapTrap is: "
            << rhs.getName() << std::endl;
  if (this != &rhs) {
    this->setName(rhs.getName());
  }
  return (*this);
}

void ClapTrap::setType(std::string type) { type_ = type; }

std::string ClapTrap::getType(void) const { return (type_); }

void ClapTrap::setName(std::string name) { name_ = name; }

std::string ClapTrap::getName(void) const { return (name_); }

void ClapTrap::setHitPoints(unsigned int amount) { hit_points_ = amount; }

unsigned int ClapTrap::getHitPoints(void) const { return (hit_points_); }

void ClapTrap::setEnergyPoints(unsigned int amount) { energy_points_ = amount; }

unsigned int ClapTrap::getEnergyPoints(void) const { return (energy_points_); }

void ClapTrap::setAttackDamage(unsigned int amount) { attack_damage_ = amount; }

unsigned int ClapTrap::getAttackDamage(void) const { return (attack_damage_); }

void ClapTrap::attack(const std::string& target) {
  unsigned int current_energy_points = getEnergyPoints();
  unsigned int current_hit_points = getHitPoints();

  if (current_energy_points > 0 && current_hit_points > 0) {
    setEnergyPoints(current_energy_points - 1);
    std::cout << getType() << " " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!"
              << "(current energy point: " << current_energy_points - 1 << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  } else {
    std::cout << getType() << " " << getName() << " can't attack " << target
              << ", because of not enough energy point or hit points."
              << "(current energy point: " << current_energy_points << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  unsigned int current_energy_points = getEnergyPoints();
  unsigned int current_hit_points = getHitPoints();

  if (current_energy_points > 0 && current_hit_points > 0) {
    if (current_hit_points - amount > current_hit_points) {
      setHitPoints(0);
    } else {
      setHitPoints(current_hit_points - amount);
    }
    std::cout << getType() << " " << getName() << " take " << amount
              << " damage "
              << "(current energy point: " << current_energy_points << ","
              << " current hit point: " << getHitPoints() << ")" << std::endl;
  } else {
    std::cout << getType() << " " << getName()
              << " can't take damage, because of not enough energy point or "
                 "hit points."
              << " (current energy point: " << current_energy_points << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  unsigned int current_energy_points = getEnergyPoints();
  unsigned int current_hit_points = getHitPoints();

  if (current_energy_points > 0 && current_hit_points > 0) {
    setHitPoints(current_hit_points + amount);
    setEnergyPoints(current_energy_points - 1);
    std::cout << getType() << " " << getName() << " is repaired with " << amount
              << " (current energy point: " << current_energy_points - 1 << ","
              << " current hit point: " << current_hit_points + amount << ")"
              << std::endl;
  } else {
    std::cout << getType() << " " << getName()
              << " can't be repaired, because of not enough energy point or "
                 "hit points."
              << "(current energy point: " << current_energy_points << ","
              << " current hit point: " << current_hit_points << ")"
              << std::endl;
  }
}
