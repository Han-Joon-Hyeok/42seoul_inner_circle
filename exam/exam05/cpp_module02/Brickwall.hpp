#ifndef BRICKWALL_HPP
#define BRICKWALL_HPP

#include "ATarget.hpp"

class Brickwall : public ATarget
{
public:
	Brickwall(void);
	~Brickwall(void);

	virtual Brickwall *clone(void) const;
};

#endif
