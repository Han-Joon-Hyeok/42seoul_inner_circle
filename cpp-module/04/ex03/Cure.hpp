#ifndef Cure_HPP
# define Cure_HPP

#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria
{
	private:
	public:
		Cure(void);
		Cure(const Cure& src);
		virtual ~Cure(void);
		Cure& operator=(Cure const& rhs);

		virtual AMateria* clone(void) const;
		virtual void use(ICharacter& target);
};

#endif
