#include "Warlock.hpp"
#include "ASpell.hpp"
#include <iostream>

Warlock::Warlock(void) {}

Warlock::Warlock(const std::string &name, const std::string &title) : name_(name), title_(title)
{
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << getName() << ": My job here is done!" << std::endl;
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
	spells_.push_back(spell);
}

void Warlock::forgetSpell(const std::string &spell)
{
	std::list<ASpell *>::iterator iter = spells_.begin();

	while (iter != spells_.end())
	{
		ASpell *find = *iter;
		if (find->getName() == spell)
		{
			spells_.erase(iter);
			return;
		}
	}
}

void Warlock::launchSpell(const std::string &spell, const ATarget &target)
{
	std::list<ASpell *>::iterator iter = spells_.begin();

	while (iter != spells_.end())
	{
		ASpell *find = *iter;
		if (find->getName() == spell)
		{
			find->launch(target);
			return;
		}
	}
}
