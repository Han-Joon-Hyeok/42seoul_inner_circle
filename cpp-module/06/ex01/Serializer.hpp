#ifndef Serializer_HPP
#define Serializer_HPP

#include <cstdint>
#include <string>

struct Data {
  std::string name;
  int age;
};

class Serializer {
 private:
  Serializer(void);

 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream& out, const Data& rhs);

#endif
