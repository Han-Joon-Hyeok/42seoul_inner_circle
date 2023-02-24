#ifndef Ice_HPP
# define Ice_HPP

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria
{
	private:
	public:
		Ice(void);
		Ice(const Ice& src);
		virtual ~Ice(void);
		Ice& operator=(Ice const& rhs);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
