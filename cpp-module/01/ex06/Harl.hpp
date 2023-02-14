#ifndef MY_STD_HPP
#define MY_STD_HPP

#include <string>

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"

typedef int LevelType;

typedef enum {
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  NONE
} LevelType_;

class Harl {
 private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

 public:
  void complain(std::string level);
};

#endif
