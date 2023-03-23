#include "BitcoinExchange.hpp"
#include <iostream>
#include <sstream>
#include <utility>
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

void BitcoinExchange::parseLine(std::string& line) {
	try {
		ft_split(line, '|');
	} catch(std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

// Non-member functions
std::string ft_strtrim(std::string& str) {
  size_t first = str.find_first_not_of(" \t\n\r");

  if (first == std::string::npos) {
    return "";
  }

  size_t last = str.find_last_not_of(" \t\n\r");

  return str.substr(first, last - first + 1);
}

std::pair<std::string, double> ft_split(std::string& str, char delimiter) {
	std::string key;
	std::string value;
	double d_value;
	std::stringstream ss(str);
	std::pair<std::string, double> pair;

	d_value = 0;
	std::getline(ss, key, delimiter);
	key = ft_strtrim(key);

	std::getline(ss, value, '\n');
	std::stringstream ss2(ft_strtrim(value));
	if ((ss2 >> d_value) && (ss2.peek() == EOF)) {
		pair = std::make_pair(key, d_value);
	} else {
		throw (InvalidInput());
	}
	return (pair);
}

const char* InvalidInput::what() const throw() {
	return ("Invalid value format");
}
