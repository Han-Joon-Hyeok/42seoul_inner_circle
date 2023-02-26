#ifndef POLYMORPH_HPP
#define POLYMORPH_HPP

#include <string>

#include "ASpell.hpp"

class Polymorph : public ASpell {
	public:
		Polymorph(void);
		virtual ~Polymorph(void);

		virtual Polymorph *clone(void) const;
};

#endif
