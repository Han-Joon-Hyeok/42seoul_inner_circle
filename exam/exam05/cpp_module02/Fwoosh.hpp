#ifndef Fwoosh_HPP
#define Fwoosh_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell {
	public:
		Fwoosh(void);
		virtual ~Fwoosh(void);
		virtual ASpell* clone(void) const;
};

#endif
