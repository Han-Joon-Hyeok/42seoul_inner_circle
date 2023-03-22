#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return (EXIT_FAILURE);
  }

  std::ifstream infile;

  infile.open(argv[1]);
  if (infile.is_open() == false) {
    std::cerr << "Error: could not open file." << std::endl;
    return (EXIT_FAILURE);
  }

}
