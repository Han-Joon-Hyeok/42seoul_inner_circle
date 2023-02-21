#include <iostream>

#include "ScavTrap.hpp"

int main(void) {
  ScavTrap bot1("joon");
  ScavTrap bot2("han");

  std::cout << std::string(50, '=') << std::endl;

  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());
  bot2.beRepaired(10);

  std::cout << std::string(50, '=') << std::endl;

  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());
  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());
  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());
  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());
  bot1.attack(bot2.getName());
  bot2.takeDamage(bot1.getAttackDamage());

  std::cout << std::string(50, '=') << std::endl;

  bot2.beRepaired(20);
  bot2.attack(bot1.getName());

  std::cout << std::string(50, '=') << std::endl;

  bot1.guardGate();
  bot2.guardGate();

  std::cout << std::string(50, '=') << std::endl;

  return (EXIT_SUCCESS);
}
