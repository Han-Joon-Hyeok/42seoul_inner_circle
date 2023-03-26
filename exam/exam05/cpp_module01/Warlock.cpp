#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <iostream>

Warlock::Warlock(const std::string& name, const std::string& title) : name_(name), title_(title) {
	std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void) {
	std::cout << getName() << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell*>::iterator it = spells_.begin();
	while (it != spells_.end()) {
		delete it->second;
		it++;
	}
}

const std::string& Warlock::getName(void) const {
	return (name_);
}

const std::string& Warlock::getTitle(void) const {
	return (title_);
}

void Warlock::setTitle(const std::string& title) {
	this->title_ = title;
}

void Warlock::introduce(void) const {
	std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell) {
	std::pair<std::string, ASpell*> pair;

	if (this->spells_.count(spell->getName())) {
		return ;
	}

	pair = std::make_pair(spell->getName(), spell->clone());
	spells_.insert(pair);
}

void Warlock::forgetSpell(std::string name) {
	if (this->spells_.count(name) == false) {
		return ;
	}

	std::map<std::string, ASpell*>::iterator it = this->spells_.find(name);
	delete it->second;
	this->spells_.erase(it);
}

void Warlock::launchSpell(std::string name, const ATarget& target) {
	if (this->spells_.count(name) == false) {
		return ;
	}

	std::map<std::string, ASpell*>::iterator it = this->spells_.find(name);
	it->second->launch(target);
}

