#ifndef Fireball_HPP
#define Fireball_HPP

#include "ASpell.hpp"

class Fireball : public ASpell {
	public:
		Fireball(void);
		virtual ~Fireball(void);
		virtual ASpell* clone(void) const;
};

#endif
