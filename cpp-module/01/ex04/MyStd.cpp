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
  std::string result;

  pos = line.find(find_);
  // When successfully found target string
  if (pos != std::string::npos) {
    result = line.substr(0, pos) + change_ +
             line.substr(pos + find_len_, line.length());
    return (result);
  }
  return (line);
}
