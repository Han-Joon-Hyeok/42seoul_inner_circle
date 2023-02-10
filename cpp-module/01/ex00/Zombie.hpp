#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define GREEN_TEXT "\033[32m"
# define YELLOW_TEXT "\033[33m"
# define CUT_TEXT "\033[0m"

# include <string>

class Zombie
{
	private:
		std::string name_;
		Zombie(void);

	public:
		Zombie(std::string name);
		~Zombie(void);

		std::string	getName(void);
		void				announce(void);
};

Zombie* newZombie(std::string name);
void		randomChump(std::string name);

#endif
