#include "Character.hpp"
#include "AMateria.hpp"

#include <iostream>

Character::Character(const std::string& name) : name_(name) {
  for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
    inventory_[idx] = NULL;
  }
}

Character::Character(const Character& src) { *this = src; }

Character::~Character(void) {
  for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
    if (inventory_[idx] != NULL) {
      delete inventory_[idx];
      inventory_[idx] = NULL;
    }
  }
}

Character& Character::operator=(Character const& rhs) {
  if (this != &rhs) {
    this->setName(rhs.getName());
    for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
      if (rhs.inventory_[idx] != NULL) {
        if (inventory_[idx] != NULL) {
          delete inventory_[idx];
        }
        inventory_[idx] = rhs.inventory_[idx]->clone();
      }
    }
  }
  return *this;
}

void Character::setName(const std::string& name) { name_ = name; }

std::string const& Character::getName(void) const { return (name_); }

void Character::equip(AMateria* m) {
  for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
    if (inventory_[idx] == NULL) {
      inventory_[idx] = m;
      return;
    }
  }
  std::cout << "[" << getName() << "] Can't equip materia!" << std::endl;
}

void Character::unequip(int idx) {
  if (isValidIndex(idx) == false) {
    return;
  }
  inventory_[idx] = NULL;
  std::cout << "Index " << GREEN_TEXT << idx << CUT_TEXT << " is unequiped."
            << std::endl;
}

void Character::use(int idx, ICharacter& target) {
  if (isValidIndex(idx) == false) {
    return;
  }
  inventory_[idx]->use(target);
}

bool Character::isValidIndex(int idx) {
  if (idx < 0 || idx >= SLOT_SIZE) {
    std::cout << "Index " << YELLOW_TEXT << idx << CUT_TEXT
              << " is out of range. [0 ~ 3]" << std::endl;
    return (false);
  }
  if (inventory_[idx] == NULL) {
    std::cout << "Index " << YELLOW_TEXT << idx << CUT_TEXT << " is empty slot."
              << std::endl;
    return (false);
  }
  return (true);
}
