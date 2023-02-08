#include "Contact.hpp"
#include "utils.hpp"

bool  isAllWhitespace(std::string str) {
  for (int idx = 0; idx < static_cast<int>(str.length()); idx += 1) {
    if (isspace(str[idx]) == false)
      return (false);
  }
  return (true);
}

int Contact::getDataCount(void) { return (data_count_); }

void Contact::setDataCount(int data_count) { data_count_ = data_count; }

int Contact::getContactIdx(void) { return (idx_); }

void Contact::setContactIdx(int idx) { idx_ = idx; }

void Contact::setFirstName(std::string input) { first_name_ = input; }

void Contact::getUserInput(std::string message,
                            void (Contact::*setFunc)(std::string)) {
  std::string input;

  std::cout << message << ": ";
  while (true) {
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      std::clearerr(stdin);
      return ;
    }

    if (std::cin.fail()) {
      printErrorMessage(FAILED_TO_READ, "");
      exit(EXIT_FAILURE);
    }

    if (isAllWhitespace(input)) {
      printWarnMessage("Empty value is not allowed", "");
    }
    else {
      (this->*setFunc)(input);
      setDataCount(getDataCount() + 1);
      return ;
    }
  }
}

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
