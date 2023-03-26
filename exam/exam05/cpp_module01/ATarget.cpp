#include "ATarget.hpp"
#include "ASpell.hpp"
#include <iostream>

ATarget::ATarget(const std::string& type) : type_(type) {
}

ATarget::ATarget(const ATarget& src) : type_(src.type_) { }

ATarget& ATarget::operator=(const ATarget& rhs) {
	if (this != &rhs) {
		this->type_ = rhs.type_;
	}
	return (*this);
}

ATarget::~ATarget(void) { }

const std::string& ATarget::getType(void) const {
	return (type_);
}

void ATarget::getHitBySpell(const ASpell& spell) const {
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}

