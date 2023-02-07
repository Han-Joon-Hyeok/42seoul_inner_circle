#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
 private:
  int idx_;
  std::string first_name_;
  std::string last_name_;
  std::string nickname_;
  std::string phone_number_;
  std::string darkest_secret_;

 public:
  void setFirstName(std::string first_name);
  void setLastName(std::string last_name);
  void setNickname(std::string nickname);
  void setPhoneNumber(std::string phone_number);
  void setDarkestSecret(std::string darkest_secret);

  void setContactIdx(int idx);
  int getContactIdx(void);

  void setUserData(void);

  void displayUserData(void);
};

#endif
