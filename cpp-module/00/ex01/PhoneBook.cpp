#include "PhoneBook.hpp"
#include "utils.hpp"

void PhoneBook::showTotalCount(void) { std::cout << total_count_ << std::endl; }

int PhoneBook::getTotalCount(void) { return (total_count_); }

void PhoneBook::setTotalCount(int count) { total_count_ = count; }

int PhoneBook::getSaveIdx(void) { return (save_idx_); }

void PhoneBook::setSaveIdx(int idx) { save_idx_ = idx; }

void PhoneBook::addNewContact(void) {
  int save_idx;
  int curr_total_count;

  if (getSaveIdx() == MAX_CONTACT_COUNT - 1) {
    setSaveIdx(0);
  } else {
    setSaveIdx(getSaveIdx() + 1);
  }

  save_idx = getSaveIdx();
  contact_[save_idx].setUserData();
  // TODO: 데이터가 모두 정상적으로 저장된 경우에만 데이터를 저장하기
  //  - 입력 도중 EOF가 들어오면 COMMAND 입력을 다시 받도록 작동

  if (contact_[save_idx].getDataCount() != 5) {
    printErrorMessage("Not enough contact information.", "Please Try again.");
  } else {
    curr_total_count = getTotalCount();
    if (curr_total_count != MAX_CONTACT_COUNT)
      setTotalCount(curr_total_count + 1);

    printColorMessage(BLUE_TEXT, "🚀 Successfully created a new contact!");
  }

}
