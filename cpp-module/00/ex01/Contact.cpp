#include "Contact.hpp"

int Contact::getContactIdx(void) { return (idx_); }

void Contact::setContactIdx(int idx) { idx_ = idx; }

void Contact::setFirstName(std::string input) { first_name_ = input; }

void Contact::setUserData(void) {
  std::string input;

  // while (true) {
  //   if (isInputAllWhitespace(input))

  // }
  std::cout << "Input your first name: ";
  std::getline(std::cin, input);
  std::cout << "HELLO" << std::endl;
  std::cout << std::endl;
  setFirstName(input);

  // std::cout << "Input your last name: ";
  // std::getline(std::cin, input);
  // std::cout << std::endl;
  // setLastName(input);

  // std::cout << "Input your nickname: ";
  // std::getline(std::cin, input);
  // std::cout << std::endl;
  // setNickname(input);

  // std::cout << "Input your phone number: ";
  // std::getline(std::cin, input);
  // std::cout << std::endl;
  // setPhoneNumber(input);

  // std::cout << "Input your darkest secret: ";
  // std::getline(std::cin, input);
  // std::cout << std::endl;
  // setDarkestSecret(input);
}

void Contact::displayUserData(void) {
  std::cout << "first_name_: " << first_name_ << std::endl;
}
