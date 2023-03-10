#include "Serializer.hpp"

#include <iostream>

uintptr_t Serializer::serialize(Data* ptr) {
  return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
  return (reinterpret_cast<Data*>(raw));
}

std::ostream& operator<<(std::ostream& out, const Data& rhs) {
  out << "name: " << rhs.name << ", age: " << rhs.age;
  return (out);
}
