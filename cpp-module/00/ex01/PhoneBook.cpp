#include "PhoneBook.hpp"
#include "utils.hpp"

int PhoneBook::getTotalCount(void) { return (total_count_); }

void PhoneBook::setTotalCount(int count) { total_count_ = count; }

int PhoneBook::getSaveIdx(void) { return (save_idx_); }

void PhoneBook::setSaveIdx(int idx) { save_idx_ = idx; }

void PhoneBook::addNewContact(void) {
  int save_idx;
  int curr_total_count;

  if (getSaveIdx() == MAX_CONTACT_COUNT) {
    setSaveIdx(0);
  }

  save_idx = getSaveIdx();
  contact_[save_idx].setUserData();

  if (contact_[save_idx].getDataCount() != 5) {
    printErrorMessage("Not enough contact information.", "Please Try again.");
  } else {
    curr_total_count = getTotalCount();
    if (curr_total_count != MAX_CONTACT_COUNT) {
      setTotalCount(curr_total_count + 1);
    }
    setSaveIdx(save_idx + 1);
    printColorMessage(BLUE_TEXT, "🚀 Successfully created a new contact!");
  }
}

void PhoneBook::displayContactsList(void) {
  int contact_count;

  contact_count = getTotalCount();
  if (contact_count == 0) {
    printColorMessage(YELLOW_TEXT, "There is no contact 🥺");
  } else {
    displayTableRow("first name", "last name", "nick name", "phone num",
                  "secret");
    for (int idx = 0; idx < contact_count; idx += 1) {
      contact_[idx].displayUserData();
    }
  }
}

void PhoneBook::displayContacts(void) {
  displayContactsList();
}
