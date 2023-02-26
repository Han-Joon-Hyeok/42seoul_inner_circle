#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <string>
#include <list>
#include "ASpell.hpp"

class SpellBook
{
public:
	SpellBook(void);
	~SpellBook(void);

	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	ASpell *createSpell(const std::string &spell);

private:
	std::list<ASpell *> spells_;
};

#endif
