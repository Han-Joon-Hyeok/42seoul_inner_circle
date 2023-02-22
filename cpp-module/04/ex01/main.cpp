#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  {
    std::cout << std::string(50, '=') << std::endl;
    std::cout << GREEN_TEXT << "SUBJECT EXAMPLE" << CUT_TEXT << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::string(50, '=') << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::string(50, '=') << std::endl;

    i->makeSound();   // will output the cat sound!
    j->makeSound();

    std::cout << std::string(50, '=') << std::endl;

    delete j;
    delete i;
  }

  {
    std::cout << std::string(50, '=') << std::endl;
    std::cout << GREEN_TEXT << "ANIMAL ARRAY EXAMPLE" << CUT_TEXT << std::endl;

    const Animal* animals[10];

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "HALF IS DOG" << CUT_TEXT << std::endl;
    for (int idx = 0; idx < 5; idx += 1) {
      animals[idx] = new Dog();
    }

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "OTHER HALF IS CAT" << CUT_TEXT << std::endl;
    for (int idx = 5; idx < 10; idx += 1) {
      animals[idx] = new Cat();
    }

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "DELETE DOGS AND CATS" << CUT_TEXT << std::endl;
    for (int idx = 0; idx < 10; idx += 1) {
      delete animals[idx];
    }
  }

  {
    std::cout << std::string(50, '=') << std::endl;
    std::cout << GREEN_TEXT << "COPY OF CAT" << CUT_TEXT << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    Cat cat1;
    Cat cat2;

    cat1.makeIdea("Hello World");
    cat2.makeIdea("Bye world");
    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "BEFORE DEEP COPY" << CUT_TEXT << std::endl;
    cat2.displayIdea();

    cat2 = cat1;

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "AFTER DEEP COPY" << CUT_TEXT << std::endl;
    cat2.displayIdea();
  }

  {
    std::cout << std::string(50, '=') << std::endl;
    std::cout << GREEN_TEXT << "COPY OF DOG" << CUT_TEXT << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    Dog* dog1 = new Dog();

    dog1->makeIdea("Hello World");

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "BEFORE DEEP COPY" << CUT_TEXT << std::endl;

    Dog* dog2 = new Dog();
    dog2->makeIdea("Bye world");
    dog2->displayIdea();

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "DEEP COPY DOG1 TO DOG2" << CUT_TEXT
              << std::endl;
    *dog2 = *dog1;

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "DELETE DOG1" << CUT_TEXT << std::endl;
    delete dog1;

    std::cout << std::string(50, '=') << std::endl;
    std::cout << YELLOW_TEXT << "AFTER DEEP COPY" << CUT_TEXT << std::endl;
    dog2->displayIdea();

    std::cout << std::string(50, '=') << std::endl;
  }

  return (EXIT_SUCCESS);
}
