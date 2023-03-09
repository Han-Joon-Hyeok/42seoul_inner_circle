#ifndef Serializer_HPP
#define Serializer_HPP

#include <cstdint>
#include <string>

struct Data {
  std::string name;
  int age;
};

class Serializer {
 public:
  Serializer(void);
  Serializer(const Serializer& src);
  virtual ~Serializer(void);
  Serializer& operator=(Serializer const& rhs);

  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);
};

std::ostream& operator<<(std::ostream& out, const Data& rhs);

#endif
