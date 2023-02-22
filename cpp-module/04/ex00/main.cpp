#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
  std::cout << std::string(50, '=') << std::endl;
  std::cout << GREEN_TEXT << "SUCCESS CASE" << CUT_TEXT << std::endl;

  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();

  std::cout << std::string(50, '=') << std::endl;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;

  std::cout << std::string(50, '=') << std::endl;

  i->makeSound();   // will output the cat sound!
  j->makeSound();
  meta->makeSound();

  std::cout << std::string(50, '=') << std::endl;

  delete meta;
  delete j;
  delete i;

  std::cout << std::string(50, '=') << std::endl;

  std::cout << YELLOW_TEXT << "FAIL CASE" << CUT_TEXT << std::endl;

  const WrongAnimal* wAnminal = new WrongAnimal();
  const WrongAnimal* wCat = new WrongCat();

  std::cout << std::string(50, '=') << std::endl;

  wCat->makeSound();
  wAnminal->makeSound();

  std::cout << std::string(50, '=') << std::endl;

  delete wAnminal;
  delete wCat;

  return (EXIT_SUCCESS);
}
