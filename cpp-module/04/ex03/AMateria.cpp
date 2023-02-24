#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria(void) : type_("") {}

AMateria::AMateria(std::string const& type) : type_(type) {}

AMateria::AMateria(const AMateria& rhs) { *this = rhs; }

AMateria::~AMateria(void) {}

AMateria& AMateria::operator=(AMateria const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

std::string const& AMateria::getType(void) const { return (type_); }

void AMateria::setType(const std::string& type) { type_ = type; }

void AMateria::use(ICharacter& target) {
  std::cout << "This an abstract use." << std::endl;
}
