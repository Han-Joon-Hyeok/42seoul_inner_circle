#include "PhoneBook.hpp"

void PhoneBook::showTotalCount(void) { std::cout << total_count_ << std::endl; }

int PhoneBook::getTotalCount(void) { return (total_count_); }

void PhoneBook::setTotalCount(int count) { total_count_ = count; }

int PhoneBook::getSaveIdx(void) { return (save_idx_); }

void PhoneBook::setSaveIdx(int idx) { save_idx_ = idx; }

void PhoneBook::addNewContact(void) {
  int curr_total_count;

  if (getSaveIdx() == MAX_CONTACT_COUNT - 1) {
    setSaveIdx(0);
  } else {
    setSaveIdx(getSaveIdx() + 1);
  }

  contact_[getSaveIdx()].setUserData();
  // contact_[save_idx].displayUserData();

  curr_total_count = getTotalCount();
  if (curr_total_count != MAX_CONTACT_COUNT)
    setTotalCount(curr_total_count + 1);

  std::cout << "🚀 Successfully created a new contact!" << std::endl;
}
