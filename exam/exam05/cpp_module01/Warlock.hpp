#ifndef Warlock_HPP
#define Warlock_HPP

#include <string>
#include <map>

class ASpell;
class ATarget;

class Warlock {
	private:
		Warlock(void);
		Warlock(const Warlock& src);
		Warlock& operator=(const Warlock& rhs);

		std::string name_;
		std::string title_;
		std::map<std::string, ASpell*> spells_;

	public:
		Warlock(const std::string& name, const std::string& title);
		~Warlock(void);

		const std::string& getName(void) const;
		const std::string& getTitle(void) const;
		void setTitle(const std::string& title);
		void introduce(void) const;

		void learnSpell(ASpell* spell);
		void forgetSpell(std::string name); // const std::string& or std::string
		void launchSpell(std::string name, const ATarget& target);
};

#endif
