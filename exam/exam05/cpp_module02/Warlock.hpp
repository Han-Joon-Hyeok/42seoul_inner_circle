#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <string>
#include <list>
#include "SpellBook.hpp"

class ASpell;
class ATarget;

class Warlock
{
public:
	Warlock(const std::string &name, const std::string &title);
	~Warlock(void);

	const std::string &getName(void) const;
	const std::string &getTitle(void) const;
	void setTitle(const std::string &title);
	void introduce(void) const;

	void learnSpell(ASpell *spell);
	void forgetSpell(const std::string &spell);
	void launchSpell(const std::string &spell, const ATarget &target);

private:
	Warlock(void);

	std::string name_;
	std::string title_;
	SpellBook *spells_;
};

#endif
