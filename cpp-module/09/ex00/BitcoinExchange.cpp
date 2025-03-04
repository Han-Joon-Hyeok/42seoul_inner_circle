#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange(const std::string& file) {
  std::ifstream infile;
  std::string line;
  std::string date;
  std::string value;
  double d_value;
  std::pair<std::string, double> pair;

  infile.open(file);
  if (infile.is_open() == false) {
    std::cout << "Error: can't open " << file << std::endl;
    exit(EXIT_FAILURE);
  }
  try {
    std::getline(infile, line);
    while (std::getline(infile, line)) {
      std::stringstream ss(line);

      std::getline(ss, date, ',');
      std::getline(ss, value, '\n');
      std::stringstream ss2(value);

      this->validateDateFormat(date);
      if ((ss2 >> d_value) && (ss2.peek() == EOF)) {
        pair = std::make_pair(date, d_value);
        this->chart_.insert(pair);
      } else {
        throw(std::runtime_error(""));
      }
    }
  } catch (std::exception& e) {
    std::cout << "Error: invalid data found in DB file => " << file
              << std::endl;
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
    : chart_(src.chart_.begin(), src.chart_.end()) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs) {
  if (this != &rhs) {
    this->chart_ = rhs.chart_;
  }
  return *this;
}

bool BitcoinExchange::isValidHeader(std::ifstream& infile,
                                    const std::string& first,
                                    const std::string& second) {
  std::string line;

  std::getline(infile, line, '|');
  line = ft_strtrim(line);
  if (line != first) {
    return (false);
  }
  std::getline(infile, line, '\n');
  line = ft_strtrim(line);
  if (line != second) {
    return (false);
  }
  return (true);
}

void BitcoinExchange::parseLine(std::string& line) {
  try {
    std::pair<std::string, double> pair;
    std::map<std::string, double>::iterator it;
    double balance;

    pair = splitKeyPair(line, '|');
    it = this->chart_.find(pair.first);
    if (it->first != pair.first) {
      it = this->chart_.lower_bound(pair.first);
      if (it == this->chart_.begin() && it->first != pair.first) {
        std::cout << "Error: there is no date in DB => " << pair.first
                  << std::endl;
        throw(InvalidInput());
      }
      --it;
    }
    balance = (pair.second) * (it->second);
    std::cout << std::setprecision(10);
    std::cout << pair.first << " => " << pair.second << " = " << balance
              << std::endl;
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
      std::cout << "Error: not a positive number. => " << ss2.str()
                << std::endl;
      throw(InvalidInput());
    }
    if (d_value > 1000) {
      std::cout << "Error: too large a number. => " << ss2.str() << std::endl;
      throw(InvalidInput());
    }
    pair = std::make_pair(key, d_value);
  } else {
    std::cout << "Error: invalid value format => " << ss2.str() << std::endl;
    throw(InvalidInput());
  }
  return (pair);
}

void BitcoinExchange::validateDateFormat(const std::string& date) {
  std::string::const_iterator it;

  it = date.begin();
  // Year
  for (; *it != '-'; ++it) {
    if (std::isdigit(*it) == false) {
      std::cout << "Error: Invalid date format. => " << date << std::endl;
      throw(InvalidInput());
    }
  }
  if (*(it++) != '-') {
    std::cout << "Error: Invalid date format. => " << date << std::endl;
    throw(InvalidInput());
  }

  // Month
  if ((*it == '0' || *(it) == '1') == false) {
    std::cout << "Error: Invalid date format. => " << date << std::endl;
    throw(InvalidInput());
  }
  ++it;
  if ((*std::prev(it) == '0' && *it == '0') ||
      (*std::prev(it) == '1' && *it > '2') || std::isdigit(*it) == false) {
    std::cout << "Error: Invalid date format. => " << date << std::endl;
    throw(InvalidInput());
  }
  ++it;

  if (*it != '-') {
    std::cout << "Error: Invalid date format. => " << date << std::endl;
    throw(InvalidInput());
  }

  ++it;
  // Day
  if (*it < '0' || *it > '3') {
    std::cout << "Error: Invalid date format. => " << date << std::endl;
    throw(InvalidInput());
  }
  ++it;
  if ((*std::prev(it) == '0' && *it == '0') || (*std::prev(it) == '3' && *it > '1') || *it < '0' || *it > '9') {
    std::cout << "Error: Invalid date format. => " << date << std::endl;
    throw(InvalidInput());
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
