#include "MyStd.hpp"

#include <iostream>

MyStd::MyStd(const char *find, const char *change) {
  find_ = std::string(find);
  change_ = std::string(change);
  find_len_ = find_.length();
  change_len_ = change_.length();
}

std::string MyStd::replace(std::string &line) {
  size_t pos;
  size_t start;
  std::string result;

  pos = line.find(find_);
  if (pos == std::string::npos) {
    return (line);
  }
  start = pos + find_len_;
  while (true) {
    result += change_;
    pos = line.find(find_, start);
    if (pos == std::string::npos) {
      result += line.substr(start, line.length() - start);
      break ;
    }
    result += line.substr(start, pos - start);
    start = pos + 1;
  }
  return (result);
}
