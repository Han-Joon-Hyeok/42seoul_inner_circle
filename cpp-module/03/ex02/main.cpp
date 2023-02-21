#include <iostream>

#include "FragTrap.hpp"

int main(void) {
  FragTrap bot1("joon");
  FragTrap bot2("han");

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

  std::cout << std::string(50, '=') << std::endl;

  bot2.beRepaired(20);
  bot2.attack(bot1.getName());

  std::cout << std::string(50, '=') << std::endl;

  bot1.highFiveGuys();
  bot2.highFiveGuys();

  std::cout << std::string(50, '=') << std::endl;

  return (EXIT_SUCCESS);
}
