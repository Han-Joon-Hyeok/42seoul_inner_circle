#ifndef SpellBook_HPP
#define SpellBook_HPP

#include <string>
#include <map>

class ASpell;

class SpellBook {
	private:
		SpellBook(const SpellBook& src);
		SpellBook& operator=(const SpellBook& rhs);

		std::map<std::string, ASpell*> spells_;

	public:
		SpellBook(void);
		~SpellBook(void);

		void learnSpell(ASpell* spell);
		void forgetSpell(const std::string& spell);
		ASpell* createSpell(const std::string& spell);

};

#endif
