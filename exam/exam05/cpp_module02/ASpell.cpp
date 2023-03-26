#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

ASpell::ASpell(const std::string& name, const std::string& effects) : name_(name), effects_(effects) {
}

ASpell::~ASpell(void) {
}

ASpell::ASpell(const ASpell& src) : name_(src.name_), effects_(src.effects_) {
}

ASpell& ASpell::operator=(const ASpell& rhs) {
	if (this != &rhs) {
		this->name_ = rhs.name_;
		this->effects_ = rhs.effects_;
	}
	return (*this);
}

const std::string& ASpell::getName(void) const {
	return (name_);
}

const std::string& ASpell::getEffects(void) const {
	return (effects_);
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}
