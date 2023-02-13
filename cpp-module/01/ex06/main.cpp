#include <iostream>
#include <string>

#include "Harl.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << YELLOW_TEXT << "execute file should be: [./harlFilter level]"
              << CUT_TEXT << std::endl;
    exit(EXIT_FAILURE);
  }

  Harl harl;
  harl.complain(std::string(argv[1]));

  return (EXIT_SUCCESS);
}
