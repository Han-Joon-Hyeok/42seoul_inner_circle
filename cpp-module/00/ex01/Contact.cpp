#include "Contact.hpp"

void Contact::getUserInput(std::string message,
                            void (Contact::*setFunc)(std::string)) {
  std::string input;

  std::cout << message << ": ";
  std::getline(std::cin, input);
  std::cout << std::endl;
  (this->*setFunc)(input);
}

int Contact::getContactIdx(void) { return (idx_); }

void Contact::setContactIdx(int idx) { idx_ = idx; }

void Contact::setFirstName(std::string input) { first_name_ = input; }

void Contact::setUserData(void) {
  std::string input;

  // while (true) {
  //   if (isInputAllWhitespace(input))

  // }
  getUserInput("Input your first name", &Contact::setFirstName);
  displayUserData();
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
