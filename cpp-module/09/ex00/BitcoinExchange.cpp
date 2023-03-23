#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

// BitcoinExchange::BitcoinExchange(void)
// {
// }

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
// {
// }

// BitcoinExchange::~BitcoinExchange(void)
// {
// }

// BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
// {
// 	if (this != &rhs)
// 	{
// 	}
// 	return *this;
// }

bool BitcoinExchange::isValidHeader(std::ifstream& infile) {
	std::string line;

	std::getline(infile, line, '|');
	line = ft_strtrim(line);
	if (line != "date") {
		return (false);
	}
	std::getline(infile, line, '\n');
	line = ft_strtrim(line);
	if (line != "value") {
		return (false);
	}
	return (true);
}

std::string ft_strtrim(std::string s) {
  size_t first = s.find_first_not_of(" \t\n\r");

  if (first == std::string::npos) {
    return "";
  }

  size_t last = s.find_last_not_of(" \t\n\r");

  return s.substr(first, last - first + 1);
}
