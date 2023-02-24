#ifndef Character_HPP
#define Character_HPP

#define SLOT_SIZE 4
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  AMateria* inventory_[SLOT_SIZE];
  std::string name_;

 public:
  Character(void);
  Character(const std::string& name);
  Character(const Character& src);
  virtual ~Character(void);
  Character& operator=(Character const& rhs);

  void setName(const std::string& name);
  virtual std::string const& getName(void) const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

  bool isValidIndex(int idx);
};

#endif
