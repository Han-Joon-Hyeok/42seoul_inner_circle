#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

#include <string>

class WrongAnimal {
 public:
	WrongAnimal(void);
  WrongAnimal(const std::string& name);
	virtual ~WrongAnimal(void);
  WrongAnimal(const WrongAnimal& rhs);
  WrongAnimal& operator=(const WrongAnimal& rhs);

  const std::string& getType(void) const;
	void  makeSound(void) const; // It doesn't have virtual keyword

 protected:
  std::string type;

};

#endif
