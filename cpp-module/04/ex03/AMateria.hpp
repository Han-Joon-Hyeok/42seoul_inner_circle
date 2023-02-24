#ifndef AMateria_HPP
# define AMateria_HPP

#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string type_;

	public:
		AMateria(void);
		AMateria(std::string const& type);
		AMateria(const AMateria& src);
		virtual ~AMateria(void);
		AMateria& operator=(AMateria const& rhs);

		std::string const& getType(void) const;
		void setType(const std::string& type);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
