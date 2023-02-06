#include "PhoneBook.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"
#define ERROR_HEADER "[ERROR] "

enum CommandType { ADD, SEARCH, EXIT, INVALID_COMMAND };

CommandType getCommandType(std::string command) {
  if (command == "ADD") return (ADD);
  if (command == "SEARCH") return (SEARCH);
  if (command == "EXIT") return (EXIT);
  return (INVALID_COMMAND);
}

int main(int argc, char **argv) {
  (void)argv;
  std::string command;
  CommandType command_type;
  PhoneBook 	my_phone_book;

  if (argc != 1) {
    std::cout << YELLOW_TEXT << ERROR_HEADER << CUT_TEXT
              << "execute file format should be: [./phonebook]" << std::endl;
    return (EXIT_FAILURE);
  }

  std::cout << my_phone_book.show_count() << std::endl;

  while (true) {
    std::cout << GREEN_TEXT << "ENTER COMMAND: [ADD, SEARCH, EXIT] " << CUT_TEXT
              << std::endl
              << "> ";
    std::cin >> command;
    command_type = getCommandType(command);

    switch (command_type) {
      case SEARCH:
        /* code */
        break;
      case ADD:
        /* code */
        break;
      case EXIT:
        std::cout << BLUE_TEXT << "Goodbye!👋" << CUT_TEXT << std::endl;
        return (EXIT_SUCCESS);
      default:
        std::cout << YELLOW_TEXT << ERROR_HEADER << CUT_TEXT
                  << "Invalid command. Please try again." << std::endl;
        break;
    }
  }
}
