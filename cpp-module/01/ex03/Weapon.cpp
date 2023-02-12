#include "Weapon.hpp"

Weapon::Weapon(void) {
  
}

Weapon::Weapon(std::string type) {
  setType(type);
}

const std::string& Weapon::getType(void) {
  const std::string &typeREF = type_;
  return (typeREF);
}

void  Weapon::setType(std::string type) {
  type_ = type;
}
