/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:18:14 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/10 09:18:24 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ios>
#include <limits>
#include <string>

#include "PhoneBook.hpp"
#include "utils.hpp"

int main(int argc, char** argv) {
  std::string command;
  PhoneBook my_phone_book;

  if (argc != 1) {
    printErrorMessage(INVALID_EXECUTE_FORMAT, argv[1]);
    return (EXIT_FAILURE);
  }

  while (true) {
    showPrompt(COMMAND_PROMPT, command);

    if (std::cin.eof()) {
      std::cout << std::endl;
      printColorMessage(BLUE_TEXT, "Goodbye!👋");
      break;
    }

    if (std::cin.fail()) {
      printErrorMessage(FAILED_TO_READ, "");
      break;
    }

    switch (getCommandType(command)) {
      case SEARCH:
        my_phone_book.displayContacts();
        break;
      case ADD:
        my_phone_book.addNewContact();
        break;
      case EXIT:
        printColorMessage(BLUE_TEXT, "Goodbye!👋");
        return (EXIT_SUCCESS);
      default:
        printWarnMessage(INVALID_COMMAND, command);
        break;
    }
  }
}
