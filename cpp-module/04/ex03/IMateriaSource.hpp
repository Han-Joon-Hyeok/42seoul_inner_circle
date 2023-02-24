#ifndef IMateriaSource_HPP
# define IMateriaSource_HPP

#include <string>

class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {};
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
