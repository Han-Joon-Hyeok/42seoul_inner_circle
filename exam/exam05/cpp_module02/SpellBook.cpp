#include "SpellBook.hpp"
#include <iostream>

SpellBook::SpellBook(void) {}

SpellBook::~SpellBook(void)
{
	std::list<ASpell *>::iterator iter = spells_.begin();

	while (iter != spells_.end())
	{
		ASpell *find = *iter;
		delete find;
		spells_.erase(iter);
	}
}

void SpellBook::learnSpell(ASpell *spell)
{
	spells_.push_back(spell->clone());
}

void SpellBook::forgetSpell(const std::string &spell)
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

ASpell* SpellBook::createSpell(const std::string &spell)
{
	std::list<ASpell *>::iterator iter = spells_.begin();

	while (iter != spells_.end())
	{
		ASpell *find = *iter;
		if (find->getName() == spell)
		{
			return (find->clone());
		}
	}
}
