#include <iostream>

#include "RPN.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error: argument should be passed only one." << std::endl;
    return (EXIT_FAILURE);
  }

  RPN rpn;
  

  return (EXIT_SUCCESS);
}
