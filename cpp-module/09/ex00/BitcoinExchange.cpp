#include "BitcoinExchange.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(void) {}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
// {
// }

BitcoinExchange::~BitcoinExchange(void) {}

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
    std::pair<std::string, double> pair;

    pair = splitKeyPair(line, '|');
  } catch (std::exception& e) {
    (void)e;
  }
}

std::pair<std::string, double> BitcoinExchange::splitKeyPair(std::string& str,
                                                             char delimiter) {
  std::string key;
  std::string value;
  double d_value;
  std::stringstream ss(str);
  std::pair<std::string, double> pair;

  d_value = 0;
  std::getline(ss, key, delimiter);
  key = ft_strtrim(key);
  this->validateDateFormat(key);

  std::getline(ss, value, '\n');
  std::stringstream ss2(ft_strtrim(value));
  if ((ss2 >> d_value) && (ss2.peek() == EOF)) {
		if (d_value < 0) {
    	std::cerr << "Error: not a positive number. => " <<  ss2.str() << std::endl;
			throw (InvalidInput());
		}
		if (d_value > 1000) {
    	std::cerr << "Error: too large a number. => " <<  ss2.str() << std::endl;
			throw (InvalidInput());
		}
    pair = std::make_pair(key, d_value);
  } else {
    std::cerr << "Error: invalid value format => " <<  ss2.str() << std::endl;
		throw (InvalidInput());
  }
  return (pair);
}

void BitcoinExchange::validateDateFormat(std::string& date) {
  std::stringstream ss(date);
  std::tm tm = {};

  ss >> std::get_time(&tm, "%Y-%m-%d");
  if (ss.fail()) {
    std::cerr << "Error: invalid date format => " << date << std::endl;
		throw (InvalidInput());
  }
}

std::string BitcoinExchange::ft_strtrim(std::string& str) {
  size_t first = str.find_first_not_of(" \t\n\r");

  if (first == std::string::npos) {
    return "";
  }

  size_t last = str.find_last_not_of(" \t\n\r");

  return str.substr(first, last - first + 1);
}

const char* InvalidInput::what() const throw() { return (""); }
