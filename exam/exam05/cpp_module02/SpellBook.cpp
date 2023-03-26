#include "SpellBook.hpp"
#include "ASpell.hpp"
#include <iostream>

SpellBook::SpellBook(void) {
}

SpellBook::~SpellBook(void) {
	std::map<std::string, ASpell*>::iterator it = spells_.begin();
	while (it != spells_.end()) {
		delete it->second;
		it++;
	}
}

void SpellBook::learnSpell(ASpell* spell) {
	if (this->spells_.count(spell->getName())) {
		return ;
	}

	std::pair<std::string, ASpell*> pair;

	pair = std::make_pair(spell->getName(), spell->clone());
	spells_.insert(pair);
}

void SpellBook::forgetSpell(const std::string& spell) {
	if (this->spells_.count(spell) == false) {
		return ;
	}

	std::map<std::string, ASpell*>::iterator it = this->spells_.find(spell);
	delete it->second;
	this->spells_.erase(it);
}

ASpell* SpellBook::createSpell(const std::string& spell) {
	if (this->spells_.count(spell) == false) {
		return (NULL);
	}

	std::map<std::string, ASpell*>::iterator it = this->spells_.find(spell);
	return (it->second->clone());
}
