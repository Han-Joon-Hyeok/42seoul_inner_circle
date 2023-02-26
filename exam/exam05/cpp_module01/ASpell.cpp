#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

ASpell::ASpell(void) {}

ASpell::ASpell(const std::string &name, const std::string &effects) : name_(name), effects_(effects)
{
}

ASpell::~ASpell(void)
{
}

const std::string &ASpell::getName(void) const
{
	return (name_);
}

const std::string &ASpell::getEffects(void) const
{
	return (effects_);
}

void ASpell::setEffects(const std::string &effects)
{
	effects_ = effects;
}

void ASpell::launch(const ATarget& target) const {
	target.getHitBySpell(*this);
}
