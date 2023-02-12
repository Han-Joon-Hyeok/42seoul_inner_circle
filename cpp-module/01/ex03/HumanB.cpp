#include "HumanB.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanB::HumanB(std::string name)
    : name_(name) {}

std::string HumanB::getName(void) { return (name_); }

void HumanB::setName(std::string name) { name_ = name; }

void HumanB::attack(void) {
  std::cout << GREEN_TEXT << getName() << CUT_TEXT << " attacks with their "
            << GREEN_TEXT << weapon_->getType() << CUT_TEXT << std::endl;
  std::cout << "weapon_: " << BLUE_TEXT << &weapon_ << CUT_TEXT << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
  weapon_ = &weapon;
}
