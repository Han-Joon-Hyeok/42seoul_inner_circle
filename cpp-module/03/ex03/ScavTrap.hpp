#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 private:
  std::string type_;

 public:
  ScavTrap(void);
  ScavTrap(std::string name);
  ~ScavTrap(void);
  ScavTrap(const ScavTrap& rhs);
  ScavTrap& operator=(const ScavTrap& rhs);

  void guardGate(void);
};

#endif
