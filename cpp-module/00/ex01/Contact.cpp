#include "Contact.hpp"

#include "utils.hpp"

bool isAllWhitespace(std::string str) {
  for (int idx = 0; idx < static_cast<int>(str.length()); idx += 1) {
    if (isspace(str[idx]) == false) {
      return (false);
    }
  }
  return (true);
}

int Contact::getDataCount(void) { return (data_count_); }

void Contact::setDataCount(int data_count) { data_count_ = data_count; }

int Contact::getContactIdx(void) { return (idx_); }

void Contact::setContactIdx(int idx) { idx_ = idx; }

void Contact::setFirstName(std::string input) { first_name_ = input; }

void Contact::setLastName(std::string input) { last_name_ = input; }

void Contact::setNickname(std::string input) { nickname_ = input; }

void Contact::setPhoneNumber(std::string input) { phone_number_ = input; }

void Contact::setDarkestSecret(std::string input) { darkest_secret_ = input; }

void Contact::getUserInput(std::string message,
                            void (Contact::*setFunc)(std::string)) {
  std::string input;

  if (std::cin.eof()) {
    return;
  }

  while (true) {
    std::cout << message << ": ";
    std::getline(std::cin, input);

    if (std::cin.eof()) {
      return;
    }

    if (std::cin.fail()) {
      printErrorMessage(FAILED_TO_READ, "");
      exit(EXIT_FAILURE);
    }

    if (isAllWhitespace(input)) {
      printWarnMessage("Empty value is not allowed", "Please try again.");
    } else {
      (this->*setFunc)(input);
      setDataCount(getDataCount() + 1);
      return;
    }
  }
}

void Contact::setUserData(void) {
  std::string input;

  getUserInput("Input your first name", &Contact::setFirstName);
  getUserInput("Input your last name", &Contact::setLastName);
  getUserInput("Input your nickname", &Contact::setNickname);
  getUserInput("Input your phone number", &Contact::setPhoneNumber);
  getUserInput("Input your darkest secret", &Contact::setDarkestSecret);
  if (std::cin.eof()) {
    std::cin.clear();
    std::clearerr(stdin);
  }
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
  std::cout << "last_name_: " << last_name_ << std::endl;
  std::cout << "nickname_: " << nickname_ << std::endl;
  std::cout << "phone_number_: " << phone_number_ << std::endl;
  std::cout << "darkest_secret_: " << darkest_secret_ << std::endl;
}
