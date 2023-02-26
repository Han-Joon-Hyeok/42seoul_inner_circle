#include "Warlock.hpp"
#include "ASpell.hpp"
#include <iostream>

Warlock::Warlock(void) {
	spells_ = new SpellBook();
}

Warlock::Warlock(const std::string &name, const std::string &title) : name_(name), title_(title)
{
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << getName() << ": My job here is done!" << std::endl;
	delete spells_;
}

const std::string &Warlock::getName(void) const
{
	return (name_);
}

const std::string &Warlock::getTitle(void) const
{
	return (title_);
}

void Warlock::setTitle(const std::string &title)
{
	title_ = title;
}

void Warlock::introduce(void) const
{
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	spells_->learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spell)
{
	spells_->forgetSpell(spell);
}

void Warlock::launchSpell(const std::string &spell, const ATarget &target)
{
	ASpell* find = spells_->createSpell(spell);
	find->launch(target);
	delete find;
}
