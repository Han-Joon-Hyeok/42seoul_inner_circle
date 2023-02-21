#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 private:
  std::string type_;

 public:
  FragTrap(void);
  FragTrap(std::string name);
  ~FragTrap(void);
  FragTrap(const FragTrap& rhs);
  FragTrap& operator=(const FragTrap& rhs);

  void highFiveGuys(void);
};

#endif
