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
  contact_[save_idx].setContactIdx(save_idx);

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

/*
  1. 음수는 무조건 받지 않는다.
  2. int 범위를 벗어난 값이라면 오류 처리
    - 오버플로우가 발생하는 순간부터 오류처리
  3. + 기호는 받지 않는다.
  4. 공백도 받지 않는다.

  반환값이 음수라면 에러가 발생한 것으로 간주
*/
int  convertStringToInt(std::string user_input) {
  int result = 0;

  if (user_input.find('-') || user_input.find('+')) {
    return (ERROR);
  }
  for (int idx = 0; idx < (int)user_input.length(); idx += 1) {
    if (isdigit(user_input[idx])) {
      result = (result * 10) + static_cast<int>(user_input[idx]);
      if (result >= MAX_CONTACT_COUNT) {
        return (ERROR);
      }
    } else {
      return (ERROR);
    }
  }
  return (result);
}

void PhoneBook::displayContacts(void) {
  int contact_count;
  int search_idx;
  std::string user_input;

  contact_count = getTotalCount();
  if (contact_count == 0) {
    printColorMessage(YELLOW_TEXT, "There is no contact 🥺");
    return;
  }

  displayTableRow("first name", "last name", "nick name", "phone num",
                  "secret");
  for (int idx = 0; idx < contact_count; idx += 1) {
    contact_[idx].displayUserData();
  }

  while (true) {
    showPrompt("Enter search index [0 ~ 7]: ", user_input);
    //TODO: ctrl + d 입력 시 무한반복 멈추기
    search_idx = convertStringToInt(user_input);
    if (search_idx == ERROR) {
      printErrorMessage("You entered invalid index. Please try again.",
                        user_input);
    } else {
      contact_[search_idx].displayUserData();
      break;
    }
  }
}
