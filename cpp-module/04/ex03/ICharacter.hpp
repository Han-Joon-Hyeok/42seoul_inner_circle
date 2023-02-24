#ifndef ICharacter_HPP
# define ICharacter_HPP

#include "AMateria.hpp"
#include <string>

class ICharacter
{
	public:
		virtual ~ICharacter(void);
		virtual std::string const& getName(void) const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
