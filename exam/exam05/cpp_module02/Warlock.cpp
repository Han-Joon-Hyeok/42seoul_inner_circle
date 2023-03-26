#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <iostream>

Warlock::Warlock(const std::string& name, const std::string& title) : name_(name), title_(title) {
	std::cout << getName() << ": This looks like another boring day." << std::endl;
	this->spells_ = new SpellBook();
}

Warlock::~Warlock(void) {
	std::cout << getName() << ": My job here is done!" << std::endl;
	delete this->spells_;
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
	this->spells_->learnSpell(spell);
}

void Warlock::forgetSpell(std::string name) {
	this->spells_->forgetSpell(name);
}

void Warlock::launchSpell(std::string name, const ATarget& target) {
	ASpell* spell;

	spell = this->spells_->createSpell(name);
	if (spell == NULL) {
		return ;
	}
	spell->launch(target);
	delete spell;
}

