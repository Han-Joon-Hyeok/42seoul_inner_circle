#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB {
 private:
  std::string name_;
  Weapon *weapon_;

  HumanB(void);

 public:
  HumanB(std::string name);

  std::string getName(void);
  void setName(std::string name);

  void attack(void);
  void setWeapon(Weapon &weapon);
};

#endif
