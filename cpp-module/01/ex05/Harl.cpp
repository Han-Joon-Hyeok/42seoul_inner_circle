#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) {
  std::cout
      << GREEN_TEXT << "[DEBUG] " << CUT_TEXT
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout
      << BLUE_TEXT << "[INFO] " << CUT_TEXT
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout
      << RED_TEXT << "[WARNING] " << CUT_TEXT
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << YELLOW_TEXT << "[ERROR] " << CUT_TEXT
            << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

LevelType getLevelType(std::string level) {
  if (level == "debug") return (DEBUG);
  if (level == "info") return (INFO);
  if (level == "warning") return (WARNING);
  if (level == "error") return (ERROR);
  return (NONE);
}

void Harl::complain(std::string level) {
  switch (getLevelType(level)) {
    case DEBUG:
      this->debug();
      break;
    case INFO:
      this->info();
      break;
    case WARNING:
      this->warning();
      break;
    case ERROR:
      this->error();
      break;
    default:
      std::cout << "[" << level << "] is invalid input." << std::endl;
      break;
  }
}
