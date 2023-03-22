#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

class BitcoinExchange
{
	private:
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& src);
		virtual ~BitcoinExchange(void);
		BitcoinExchange& operator=(BitcoinExchange const& rhs);
};

#endif
