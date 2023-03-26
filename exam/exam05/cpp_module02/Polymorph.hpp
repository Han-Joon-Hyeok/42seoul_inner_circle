#ifndef Polymorph_HPP
#define Polymorph_HPP

#include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		Polymorph(void);
		virtual ~Polymorph(void);
		virtual ASpell* clone(void) const;
};

#endif
