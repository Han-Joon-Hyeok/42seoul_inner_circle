#include <cctype>
#include <cstring>
#include <iostream>

void print_str_to_uppercase(const std::string str) {
  for (int idx = 0; idx < static_cast<int>(str.length()); idx += 1) {
    std::cout << static_cast<char>(toupper(str[idx]));
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int idx = 1; idx < argc; idx += 1) {
      print_str_to_uppercase(argv[idx]);
    }
  }
  std::cout << std::endl;
  return (0);
}
