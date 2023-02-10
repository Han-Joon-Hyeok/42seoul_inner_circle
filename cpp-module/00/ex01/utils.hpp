/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhan <joonhan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:18:28 by joonhan           #+#    #+#             */
/*   Updated: 2023/02/10 09:18:29 by joonhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define WHITE_TEXT "\033[37m"
#define CUT_TEXT "\033[0m"

#define ERROR_HEADER "[ERROR] "
#define WARN_HEADER "[WARN] "

#define COMMAND_PROMPT "Enter command [ADD, SEARCH, EXIT]: "
#define FAILED_TO_READ "Failed to read input"
#define INVALID_EXECUTE_FORMAT "Please execute file: [./phonebook]"
#define INVALID_COMMAND "Invalid command. Please try again."

#define WIDTH 10
#define ERROR -1
#define HEADER -1

#include <string>

enum CommandType { ADD, SEARCH, EXIT, NONE };

void printErrorMessage(std::string message, std::string arg);
void printWarnMessage(std::string message, std::string arg);
void printColorMessage(std::string color, std::string message);
void showPrompt(std::string message, std::string &input);
CommandType getCommandType(std::string command);
void displayTableRow(int count, int idx, ...);

#endif
