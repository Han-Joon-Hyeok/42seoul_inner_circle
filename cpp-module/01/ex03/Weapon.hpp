#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"

class Weapon {
 private:
  std::string type_;
  Weapon(void);

 public:
  Weapon(std::string name);

  const std::string& getType(void);
  void setType(std::string);
};

#endif
