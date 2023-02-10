#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name) {
  Zombie* horde = new Zombie[n];

  for (int idx = 0; idx < n; idx += 1) {
    horde[idx].setName(name);
    horde[idx].setIndex(idx);
  }

  return (horde);
}
