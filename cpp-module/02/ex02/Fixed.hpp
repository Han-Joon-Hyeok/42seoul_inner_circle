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

		bool		operator>(const Fixed& rhs) const;
		bool		operator<(const Fixed& rhs) const;
		bool		operator>=(const Fixed& rhs) const;
		bool		operator<=(const Fixed& rhs) const;
		bool		operator==(const Fixed& rhs) const;
		bool		operator!=(const Fixed& rhs) const;

		static Fixed& min(Fixed& lhs, Fixed& rhs);
		static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
		static Fixed& max(Fixed& lhs, Fixed& rhs);
		static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

		Fixed(const int raw);
		Fixed(const float raw);

		float	toFloat(void) const;
		int	toInt(void) const;

		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream &out, const Fixed& rhs);

#endif
