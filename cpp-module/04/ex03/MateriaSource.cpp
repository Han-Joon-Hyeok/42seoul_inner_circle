#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource(void) {
  for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
    slot_[idx] = NULL;
  }
}

MateriaSource::MateriaSource(const MateriaSource& src) { *this = src; }

MateriaSource::~MateriaSource(void) {
  for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
    if (slot_[idx] != NULL) {
      delete slot_[idx];
      slot_[idx] = NULL;
    }
  }
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs) {
  if (this != &rhs) {
    for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
      if (rhs.slot_[idx] != NULL) {
        if (slot_[idx] != NULL) {
          delete slot_[idx];
        }
        slot_[idx] = rhs.slot_[idx]->clone();
      }
    }
  }
  return *this;
}
void MateriaSource::learnMateria(AMateria* m) {
  if (m->getType() == "ice" || m->getType() == "cure") {
    for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
      if (slot_[idx] == NULL) {
        slot_[idx] = m->clone();
        return;
      }
    }
    std::cout << "[MateriaSource] Can't learn more than 4 materias!"
              << std::endl;
  } else {
    std::cout << "[MateriaSource] Only ice or cure can learn." << std::endl;
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  if (type != "ice" && type != "cure") {
    std::cout << "[MateriaSource] Only ice or cure can create." << std::endl;
    return (0);
  }
  for (int idx = 0; idx < SLOT_SIZE; idx += 1) {
    if (slot_[idx] != NULL && slot_[idx]->getType() == type) {
      return (slot_[idx]->clone());
    }
  }
  std::cout << "[MateriaSource] There is no " << type << " in MateriaSource"
            << std::endl;
  return (0);
}
