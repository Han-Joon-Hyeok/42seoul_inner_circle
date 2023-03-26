#include "Fwoosh.hpp"
#include <iostream>

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed") {
}

Fwoosh::~Fwoosh(void) {
}

ASpell* Fwoosh::clone(void) const {
	return (new Fwoosh());
}
