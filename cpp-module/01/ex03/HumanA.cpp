#include "HumanA.hpp"

#include <iostream>

#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {}

std::string HumanA::getName(void) { return (name_); }

void HumanA::setName(std::string name) { name_ = name; }

void HumanA::attack(void) {
  std::cout << GREEN_TEXT << getName() << CUT_TEXT << " attacks with their "
            << GREEN_TEXT << weapon_.getType() << CUT_TEXT << std::endl;
  std::cout << "weapon_: " << BLUE_TEXT << &weapon_ << CUT_TEXT << std::endl;
}
