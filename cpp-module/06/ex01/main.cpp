#include <iostream>

#include "Serializer.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

int main(void) {
  {
    Data d1 = {"joonhan", 42};

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "Origin Data" << CUT_TEXT << std::endl;
    std::cout << "d1: " << d1 << std::endl;

    std::cout << std::string(50, '=') << std::endl;

    uintptr_t s1 = Serializer::serialize(&d1);
    std::cout << GREEN_TEXT << "Serialize Data to uintptr_t" << CUT_TEXT
              << std::endl;
    std::cout << "s1 address(serialized): " << s1 << std::endl;
    std::cout << "age : " << (reinterpret_cast<Data*>(s1))->age << std::endl;
    std::cout << "name: " << (reinterpret_cast<Data*>(s1))->name << std::endl;

    std::cout << std::string(50, '=') << std::endl;

    Data* ds1 = Serializer::deserialize(s1);
    std::cout << GREEN_TEXT << "Deserialize uintptr_t to Data" << CUT_TEXT
              << std::endl;
    std::cout << "ds1 address(deserialized): "
              << reinterpret_cast<uintptr_t>(ds1) << std::endl;

    std::cout << std::string(50, '=') << std::endl;

    std::cout << YELLOW_TEXT << "Deserialized Data" << CUT_TEXT << std::endl;
    std::cout << *ds1 << std::endl;
  }

  std::cout << std::string(50, '=') << std::endl;

  {
    Data* d2 = NULL;

    uintptr_t s2 = Serializer::serialize(d2);
    std::cout << "s2 address(serialized): " << s2 << std::endl;
    // segfault (because it deferences 0x00)
    // std::cout << "s2 address(serialized): " << *s2 << std::endl;

    Data* ds2 = Serializer::deserialize(s2);
    std::cout << "ds2 address(deserialized): " << ds2 << std::endl;
  }

  return (0);
}
