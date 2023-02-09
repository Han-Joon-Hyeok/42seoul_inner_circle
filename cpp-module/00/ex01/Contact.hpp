#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

enum DisplayType { PER_LINE, ONE_LINE, INPUT_RESULT };

class Contact {
 private:
  int idx_;
  int data_count_;
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  void setFirstName(std::string first_name);
  std::string getFirstName(void);

  void setLastName(std::string last_name);
  std::string getLastName(void);

  void setNickname(std::string nickname);
  std::string getNickname(void);

  void setPhoneNumber(std::string phone_number);
  std::string getPhoneNumber(void);

  void setDarkestSecret(std::string darkest_secret);
  std::string getDarkestSecret(void);

  void setDataCount(int count);
  int getDataCount(void);

  void setContactIdx(int idx);
  int getContactIdx(void);

  void setUserData(void);

  void getUserInput(std::string message, void (Contact::*setFunc)(std::string));

  void displayUserData(DisplayType type);

  Contact() {
    data_count_ = 0;
  }
};

void  getUserInput(std::string message, void (&setFunc)(std::string));

#endif
