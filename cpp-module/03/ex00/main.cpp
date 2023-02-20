#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
  ClapTrap  bot1("joon");
  ClapTrap  bot2("han");

  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());
  bot2.beRepaired(10);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.beRepaired(5);
  bot1.attack(bot2.getName());
  bot1.takeDamage(bot2.getAttackDamage());

  return (EXIT_SUCCESS);
}
