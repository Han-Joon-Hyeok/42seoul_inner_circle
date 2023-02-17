#ifndef FIXED_HPP
# define FIXED_HPP

# define GREEN_TEXT "\033[32m"
# define YELLOW_TEXT "\033[33m"
# define CUT_TEXT "\033[0m"

# include <string>
# include <iostream>

class Fixed
{
	private:
		int	raw_;
		static const int bits_ = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed &rhs);
		Fixed& operator=(const Fixed &rhs);

		Fixed&	operator++(void); // prefix
		Fixed		operator++(int);	// postfix

		Fixed		operator+(const Fixed& rhs) const;
		Fixed		operator-(const Fixed& rhs) const;
		Fixed		operator*(const Fixed& rhs) const;
		Fixed		operator/(const Fixed& rhs) const;

		Fixed(const int raw);
		Fixed(const float raw);

		float	toFloat(void) const;
		int	toInt(void) const;

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed& rhs);

#endif
