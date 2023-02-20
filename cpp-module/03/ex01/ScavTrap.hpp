#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
 private:
  ScavTrap(void);

 public:
  ScavTrap(std::string name);
  ~ScavTrap(void);
  ScavTrap(const ScavTrap& rhs);
  ScavTrap& operator=(const ScavTrap& rhs);

  void guardGate(void);
};

#endif
