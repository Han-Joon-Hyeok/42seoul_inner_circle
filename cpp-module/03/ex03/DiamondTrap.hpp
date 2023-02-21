#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 private:
  using ClapTrap::name_;

 public:
  DiamondTrap(void);
  DiamondTrap(std::string name);
  ~DiamondTrap(void);
  DiamondTrap(const DiamondTrap& rhs);
  DiamondTrap& operator=(const DiamondTrap& rhs);

  void  attack(const std::string& target);
  void  whoAmI(void);
};

#endif
