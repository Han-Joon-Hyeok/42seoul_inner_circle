#ifndef BitcoinExchange_HPP
# define BitcoinExchange_HPP

#include <fstream>

class BitcoinExchange
{
	private:
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& src);
		virtual ~BitcoinExchange(void);
		BitcoinExchange& operator=(BitcoinExchange const& rhs);

		static bool isValidHeader(std::ifstream& infile);
};

std::string ft_strtrim(std::string s);

#endif
