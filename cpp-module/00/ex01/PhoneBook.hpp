#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#define MAX_CONTACT_COUNT 8

#include "Contact.hpp"

class PhoneBook {
 private:
  int save_idx_;
  int total_count_;
  Contact contact_[MAX_CONTACT_COUNT];

 public:
  PhoneBook() {
    save_idx_ = 0;
    total_count_ = 0;
    for (int idx = 0; idx < MAX_CONTACT_COUNT; idx += 1) {
      contact_[idx].setContactIdx(idx);
    }
  }

  int getTotalCount(void);
  void setTotalCount(int count);

  int getSaveIdx(void);
  void setSaveIdx(int idx);

  void addNewContact(void);

  void displayContacts(void);

  void removeOldestContact(int idx);
};

#endif
