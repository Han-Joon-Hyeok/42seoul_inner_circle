#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA {
 private:
  std::string name_;
  Weapon &weapon_;

  HumanA(void);

 public:
  HumanA(std::string name, Weapon &weapon);

  std::string getName(void);
  void setName(std::string name);

  void attack(void);
};

#endif
