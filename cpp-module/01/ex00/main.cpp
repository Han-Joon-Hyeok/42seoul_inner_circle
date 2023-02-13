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

  Zombie *z1 = newZombie("joon");
  Zombie *z2 = newZombie("han");

  z1->announce();
  z2->announce(); // delete 를 수행하지 않으면 메모리 누수 발생

  delete z1;
  // delete z2;

  std::cout << std::string(50, '=') << std::endl;
  std::cout << "THIS IS" << YELLOW_TEXT << " STACK " << CUT_TEXT
            << "ALLOCATED ZOMBIES" << std::endl;
  std::cout << std::string(50, '=') << std::endl;

  {
    Zombie z2("JOON");
    z2.announce();
  }
  
  {
    randomChump("HAN");
  }

  return (EXIT_SUCCESS);
}
