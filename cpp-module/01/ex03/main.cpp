#include <iostream>

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {
  std::cout << std::string(50, '=') << std::endl;
  std::cout << YELLOW_TEXT << "HumanA" << CUT_TEXT << std::endl;
  std::cout << std::string(50, '=') << std::endl;

  {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    std::cout << "club   : " << BLUE_TEXT << &club << CUT_TEXT << std::endl
              << std::endl;

    club.setType("some other type of club");
    bob.attack();
    std::cout << "club   : " << BLUE_TEXT << &club << CUT_TEXT << std::endl
              << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;
  std::cout << YELLOW_TEXT << "HumanB" << CUT_TEXT << std::endl;
  std::cout << std::string(50, '=') << std::endl;

  {
    Weapon club = Weapon("crude spiked club");

    HumanB jim("Bob");
    jim.setWeapon(club);
    jim.attack();
    std::cout << "club   : " << BLUE_TEXT << &club << CUT_TEXT << std::endl
              << std::endl;
    club.setType("some other type of club");
    jim.attack();
    std::cout << "club   : " << BLUE_TEXT << &club << CUT_TEXT << std::endl
              << std::endl;
  }

  {
    Weapon club = Weapon("crude spiked club");

    HumanB hey("hey");
    hey.attack();
    
    hey.setWeapon(club);
    hey.attack();
    std::cout << "club   : " << BLUE_TEXT << &club << CUT_TEXT << std::endl
              << std::endl;
    club.setType("some other type of club");
    hey.attack();
    std::cout << "club   : " << BLUE_TEXT << &club << CUT_TEXT << std::endl
              << std::endl;
  }

  return (EXIT_SUCCESS);
}
