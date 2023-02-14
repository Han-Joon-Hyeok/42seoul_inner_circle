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

void Harl::complain(std::string level) {
  std::string levels[4] = {"debug", "info", "warning", "error"};
  void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
                                  &Harl::error};

  for (int idx = 0; idx < 4; idx += 1) {
    if (levels[idx] == level) {
      (this->*funcs[idx])();
      return;
    }
  }

  std::cout << "[" << level << "] is invalid input." << std::endl;
}
