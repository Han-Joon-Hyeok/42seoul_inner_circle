#ifndef MateriaSource_HPP
# define MateriaSource_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define SLOT_SIZE 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*	slot_[SLOT_SIZE];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& src);
		virtual ~MateriaSource(void);
		MateriaSource& operator=(MateriaSource const& rhs);

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);

		bool	isLearnedMateria(std::string const & type);
};

#endif
