#include "PhoneBook.hpp"
#include "utils.hpp"
#include <ios>
#include <limits>
#include <string>

enum CommandType { ADD, SEARCH, EXIT, NONE };

CommandType getCommandType(std::string command) {
  if (command == "ADD") return (ADD);
  if (command == "SEARCH") return (SEARCH);
  if (command == "EXIT") return (EXIT);
  return (NONE);
}

int main(int argc, char **argv) {
  std::string command;
  PhoneBook my_phone_book;

  if (argc != 1) {
    printErrorMessage(INVALID_EXECUTE_FORMAT, argv[1]);
    return (EXIT_FAILURE);
  }

  while (true) {
    showPrompt(COMMAND_PROMPT, command);

    if (std::cin.eof()) {
      printColorMessage(1, BLUE_TEXT, "Goodbye!👋");
      break;
    }

    if (std::cin.fail()) {
      printErrorMessage(FAILED_TO_READ, "");
      break;
    }

    switch (getCommandType(command)) {
      case SEARCH:
        /* code */
        break;
      case ADD:
        my_phone_book.addNewContact();
        break;
      case EXIT:
        printColorMessage(1, BLUE_TEXT, "Goodbye!👋");
        return (EXIT_SUCCESS);
      default:
        printWarnMessage(INVALID_COMMAND, command);
        break;
    }
  }

  if (std::cin.eof()) {
    printColorMessage(1, RED_TEXT, "HELLO");
    std::clearerr(stdin);
  }
}
