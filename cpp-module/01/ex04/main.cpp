#include <fstream>
#include <iostream>
#include <string>

#include "MyStd.hpp"

#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"

int main(int argc, char **argv) {
  if (argc != 4) {
    std::cout << YELLOW_TEXT << "[ERROR]" << CUT_TEXT
              << " execute format should be: [./sed filename s1 s2]"
              << std::endl;
    exit(EXIT_FAILURE);
  }

  std::ifstream infile;
  std::string line;

  infile.open(argv[1]);
  if (infile.is_open() == false) {
    std::cout << YELLOW_TEXT << "[ERROR]" << CUT_TEXT
              << " cannot open file: " << argv[1] << std::endl;
  }

  std::ofstream outfile;
  std::string replaced;

  std::string file_name = argv[1] + std::string(".replace");
  outfile.open(file_name.c_str(), std::ofstream::out | std::ofstream::trunc);
  MyStd replacer(argv[2], argv[3]);
  while (true) {
    if (infile.eof() == true) break;
    std::getline(infile, line);
    replaced = replacer.replace(line);
    outfile.write(replaced.c_str(), replaced.length());
    if (replaced.empty() == false) {
      outfile.write("\n", 1);
    }
  }
  infile.close();
  outfile.close();

  return (EXIT_SUCCESS);
}
