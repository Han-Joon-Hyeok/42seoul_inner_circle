#ifndef A_TARGET_HPP
#define A_TARGET_HPP

#include <string>

class ASpell;

class ATarget
{
public:
	ATarget(const std::string &type);
	~ATarget(void);

	const std::string &getType(void) const;
	virtual ATarget *clone(void) const = 0;
	void getHitBySpell(const ASpell& spell) const;

protected:
	ATarget(void);

	std::string type_;
};

#endif
