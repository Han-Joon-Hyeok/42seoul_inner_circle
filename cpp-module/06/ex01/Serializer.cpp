#include "Serializer.hpp"

#include <iostream>

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& src) { (void)src; }

Serializer::~Serializer(void) {}

Serializer& Serializer::operator=(Serializer const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

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
