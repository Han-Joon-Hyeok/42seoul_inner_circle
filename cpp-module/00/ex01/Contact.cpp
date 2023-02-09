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
std::string Contact::getFirstName(void) { return (first_name_); }

void Contact::setLastName(std::string input) { last_name_ = input; }
std::string Contact::getLastName(void) { return (last_name_); }

void Contact::setNickname(std::string input) { nickname_ = input; }
std::string Contact::getNickname(void) { return (nickname_); }

void Contact::setPhoneNumber(std::string input) { phone_number_ = input; }
std::string Contact::getPhoneNumber(void) { return (phone_number_); }

void Contact::setDarkestSecret(std::string input) { darkest_secret_ = input; }
std::string Contact::getDarkestSecret(void) { return (darkest_secret_); }

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

  setDataCount(0);
  getUserInput("Input your first name", &Contact::setFirstName);
  getUserInput("Input your last name", &Contact::setLastName);
  getUserInput("Input your nickname", &Contact::setNickname);
  getUserInput("Input your phone number", &Contact::setPhoneNumber);
  getUserInput("Input your darkest secret", &Contact::setDarkestSecret);
  if (std::cin.eof()) {
    std::cin.clear();
    std::clearerr(stdin);
  }
  printColorMessage(GREEN_TEXT, "You entered below");
  displayTableRow(5, HEADER, "first name", "last name", "nick name",
                  "phone num", "secret");
  displayUserData(INPUT_RESULT);
}

void Contact::displayUserData(DisplayType type) {
  int idx = getContactIdx();
  std::string first_name = getFirstName();
  std::string last_name = getLastName();
  std::string nickname = getNickname();
  std::string phone_number = getPhoneNumber();
  std::string darkest_secret = getDarkestSecret();

  if (type == PER_LINE) {
    std::cout << "idx: " << idx << std::endl;
    printColorMessage(WHITE_TEXT, "first name: " + first_name);
    printColorMessage(WHITE_TEXT, "last name: " + last_name);
    printColorMessage(WHITE_TEXT, "nickname: " + nickname);
    printColorMessage(WHITE_TEXT, "phone number: " + phone_number);
    printColorMessage(WHITE_TEXT, "darkest secret: " + darkest_secret);
  } else if (type == INPUT_RESULT) {
    displayTableRow(5, HEADER, first_name.c_str(), last_name.c_str(),
                    phone_number.c_str(), nickname.c_str(),
                    darkest_secret.c_str());
  } else {
    displayTableRow(3, idx, first_name.c_str(), last_name.c_str(),
                    nickname.c_str());
  }
}
