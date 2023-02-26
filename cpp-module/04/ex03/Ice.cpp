#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice& src) { *this = src; }

Ice::~Ice(void) {}

Ice& Ice::operator=(Ice const& rhs) {
  if (this != &rhs) {
  }
  return *this;
}

AMateria* Ice::clone(void) const { return (new Ice()); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}
