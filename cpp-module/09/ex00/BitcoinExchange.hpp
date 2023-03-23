#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <map>

class BitcoinExchange {
 private:
  BitcoinExchange(void);
  std::map<std::string, double> account_;
  std::map<std::string, double> chart_;

 public:
  BitcoinExchange(const std::string& file);
  BitcoinExchange(const BitcoinExchange& src);
  ~BitcoinExchange(void);
  BitcoinExchange& operator=(BitcoinExchange const& rhs);

  void parseLine(std::string& line);
  bool isValidHeader(std::ifstream& infile, const std::string& first, const std::string& second);
  void validateDateFormat(std::string& date);

  std::string ft_strtrim(std::string& str);
  std::pair<std::string, double> splitKeyPair(std::string& str, char delimiter);
};

class InvalidInput : public std::exception {
 public:
  virtual const char* what() const throw();
};

#endif
