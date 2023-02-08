#ifndef UTILS_HPP
#define UTILS_HPP

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define CUT_TEXT "\033[0m"

#define ERROR_HEADER "[ERROR] "
#define WARN_HEADER "[WARN] "

#define COMMAND_PROMPT "ENTER COMMAND [ADD, SEARCH, EXIT]: "
#define FAILED_TO_READ "Failed to read input"
#define INVALID_EXECUTE_FORMAT "Please execute file: [./phonebook]"
#define INVALID_COMMAND "Invalid command. Please try again."

#include <string>

void printErrorMessage(std::string message, std::string arg);
void printWarnMessage(std::string message, std::string arg);
void printColorMessage(int count, std::string color, ...);
void showPrompt(std::string message, std::string &input);

#endif
