#include "HumanB.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name_(name), weapon_(NULL) {}

std::string HumanB::getName(void) { return (name_); }

void HumanB::setName(std::string name) { name_ = name; }

void HumanB::attack(void) {
  if (weapon_ == NULL) {
    std::cout << GREEN_TEXT << getName() << CUT_TEXT
              << " doesn't have a weapon." << std::endl;
  } else {
    std::cout << GREEN_TEXT << getName() << CUT_TEXT << " attacks with their "
              << GREEN_TEXT << weapon_->getType() << CUT_TEXT << std::endl;
    std::cout << "weapon_: " << BLUE_TEXT << &weapon_ << CUT_TEXT << std::endl;
  }
}

void HumanB::setWeapon(Weapon &weapon) { weapon_ = &weapon; }
