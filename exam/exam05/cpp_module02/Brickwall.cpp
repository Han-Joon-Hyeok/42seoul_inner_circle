#include "Brickwall.hpp"
#include <iostream>

Brickwall::Brickwall(void) : ATarget("Inconspicuous Red-brick Wall") {}

Brickwall::~Brickwall(void)
{
}

Brickwall *Brickwall::clone(void) const
{
	return (new Brickwall());
}
