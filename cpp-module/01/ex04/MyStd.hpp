#ifndef MY_STD_HPP
#define MY_STD_HPP

#include <string>

class MyStd {
 private:
  std::string find_;
  std::string change_;
  size_t find_len_;
  size_t change_len_;
  MyStd(void);

 public:
  MyStd(const char *find, const char *change);
  std::string replace(std::string &line);
};

#endif
