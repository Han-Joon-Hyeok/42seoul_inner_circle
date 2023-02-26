#ifndef A_SPELL_HPP
#define A_SPELL_HPP

#include <string>

class ATarget;

class ASpell
{
public:
	ASpell(const std::string &name, const std::string &effects);
	virtual ~ASpell(void);

	const std::string &getName(void) const;
	const std::string &getEffects(void) const;
	void setEffects(const std::string &effects);
	void launch(const ATarget &target) const;
	virtual ASpell *clone(void) const = 0;

protected:
	std::string name_;
	std::string effects_;

private:
	ASpell();
};

#endif
