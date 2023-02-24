#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& src) {}

Cure::~Cure(void) {}

Cure& Cure::operator=(Cure const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

AMateria* AMateria::clone(void) const { return (new Cure()); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
