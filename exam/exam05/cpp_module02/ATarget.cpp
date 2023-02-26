#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

ATarget::ATarget(void) {}

ATarget::ATarget(const std::string &type) : type_(type)
{
}

ATarget::~ATarget(void)
{
}

const std::string &ATarget::getType(void) const
{
	return (type_);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}
