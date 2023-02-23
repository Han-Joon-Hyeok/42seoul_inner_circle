#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  {
    // Compile error: unimplemented pure virtual method 'makeSound' in 'Animal'
    // Animal  ani;
  }
  {
    Animal* cat1 = new Cat();
    Animal* dog1 = new Dog();

    cat1->makeSound();
    dog1->makeSound();

    delete cat1;
    delete dog1;
  }

  return (EXIT_SUCCESS);
}
