#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define GREEN_TEXT "\033[32m"
# define YELLOW_TEXT "\033[33m"
# define CUT_TEXT "\033[0m"

# include <string>

class Zombie
{
	private:
		int 				idx_;
		std::string name_;

	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		int					getIndex(void);
		void				setIndex(int idx);

		std::string	getName(void);
		void				setName(std::string);

		void				announce(void);
};

Zombie* zombieHorde(int n, std::string name);

#endif
