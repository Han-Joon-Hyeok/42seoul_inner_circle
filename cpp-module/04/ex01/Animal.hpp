#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

#include <string>

class Animal {
 public:
	Animal(void);
  Animal(const std::string& name);
	virtual ~Animal(void);
  Animal(const Animal& rhs);
  Animal& operator=(const Animal& rhs);

  const std::string& getType(void) const;
	virtual void  makeSound(void) const;

 protected:
  std::string type;

};

#endif
