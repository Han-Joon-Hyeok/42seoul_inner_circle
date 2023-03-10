#ifndef Generator_HPP
# define Generator_HPP

#include "Base.hpp"

class Generator
{
	private:
	public:
		static Base* generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
};

#endif
