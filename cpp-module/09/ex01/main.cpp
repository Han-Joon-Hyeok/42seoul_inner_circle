#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cout << "Error: argument should be passed only one." << std::endl;
    return (EXIT_FAILURE);
  }

  RPN rpn;

  rpn.calculate(std::string(argv[1]));

  return (EXIT_SUCCESS);
}
