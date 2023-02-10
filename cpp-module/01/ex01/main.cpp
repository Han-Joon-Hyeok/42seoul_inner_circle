#include <iostream>

#include "Zombie.hpp"

int main(int argc, char **argv) {
  (void)argv;

  if (argc != 1) {
    std::cout << "[ERROR] execute file format should be: [./zombie]"
              << std::endl;
    return (EXIT_FAILURE);
  }

  std::cout << std::string(50, '=') << std::endl;
  std::cout << "THIS IS" << GREEN_TEXT << " HEAP " << CUT_TEXT
            << "ALLOCATED ZOMBIES" << std::endl;
  std::cout << std::string(50, '=') << std::endl;

  int num = 5;
  Zombie *horde = zombieHorde(num, "joonhan");

  for (int idx = 0; idx < num; idx += 1) {
    horde[idx].announce();
  }

  delete[] horde;

  return (EXIT_SUCCESS);
}
