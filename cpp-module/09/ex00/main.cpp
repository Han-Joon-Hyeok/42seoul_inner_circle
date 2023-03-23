#include <fstream>
#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return (EXIT_FAILURE);
  }

  BitcoinExchange ex;

  std::ifstream infile;

  infile.open(argv[1]);
  if (infile.is_open() == false) {
    std::cerr << "Error: could not open file." << std::endl;
    return (EXIT_FAILURE);
  }

  if (ex.isValidHeader(infile) == false) {
    std::cerr << "Error: header format should be: [date | value]" << std::endl;
    return (EXIT_FAILURE);
  }

  std::string line;
  while (std::getline(infile, line)) {
    ex.parseLine(line);
  }

  return (EXIT_SUCCESS);
}
