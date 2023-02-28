#include <iostream>

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void) {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  src->learnMateria(new Cure());
  src->learnMateria(new Cure());

  src->learnMateria(new Cure()); // [MateriaSource] Can't learn more than 4 materias!

  ICharacter* me = new Character("me");

  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  tmp = src->createMateria("nope"); // [MateriaSource] Only ice or cure can create.
  me->equip(tmp); // [me] Can't equip empty materia!

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);

  me->use(-1, *bob); // Index -1 is out of range. [0 ~ 3]
  me->use(5, *bob); // Index 5 is out of range. [0 ~ 3]
  
  delete bob;
  delete me;
  delete src;

  return (EXIT_SUCCESS);
}
