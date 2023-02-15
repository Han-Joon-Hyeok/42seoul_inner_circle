#ifndef FIXED_HPP
# define FIXED_HPP

# define GREEN_TEXT "\033[32m"
# define YELLOW_TEXT "\033[33m"
# define CUT_TEXT "\033[0m"

# include <string>

class Fixed
{
	private:
		int	value_;
		static const int bits_ = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &rhs);
		Fixed& operator=(const Fixed &rhs);

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};


#endif
