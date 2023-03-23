#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <fstream>
#include <map>

class BitcoinExchange {
 private:
  std::map<std::string, double> account_;

 public:
  BitcoinExchange(void);
  BitcoinExchange(const BitcoinExchange& src);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);

  static void parseLine(std::string& line);
  static bool isValidHeader(std::ifstream& infile);
};

std::string ft_strtrim(std::string& str);
std::pair<std::string, double> ft_split(std::string& str, char delimiter);

class InvalidInput : public std::exception {
 public:
  virtual const char* what() const throw();
};

#endif
