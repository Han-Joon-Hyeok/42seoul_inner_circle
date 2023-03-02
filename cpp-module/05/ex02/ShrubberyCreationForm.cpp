#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

#include "Bureaucrat.hpp"

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define CUT_TEXT "\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
    : AForm(name, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
    : AForm(src.getName(), 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const& rhs) {
  if (this != &rhs) {
    this->setIsSigned(rhs.getIsSigned());
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (this->getIsSigned() == false) {
    throw(AForm::NotSignedException());
  }
  if (executor.getGrade() > this->getExecuteGrade()) {
    throw(AForm::GradeTooLowException());
  }
  std::string file_name = executor.getName() + "_shrubbery";

  std::ofstream outfile;

  outfile.open(file_name.c_str(), std::ofstream::out | std::ofstream::trunc);
  if (outfile.is_open() == false) {
    std::cout << RED_TEXT << "[ERROR]" << CUT_TEXT
              << " cannot open file: " << file_name << std::endl;
    exit(EXIT_FAILURE);
  }

  outfile << "     oxoxoo    ooxoo\n"
          << "    ooxoxo oo  oxoxooo\n"
          << "   oooo xxoxoo ooo ooox\n"
          << "  oxo o oxoxo  xoxxoxo\n"
          << "   oxo xooxoooo o ooo\n"
          << "     ooo\\oo\\  /o/o\n"
          << "         \\  \\/ /\n"
          << "          |   /\n"
          << "          |  |\n"
          << "          | D|\n"
          << "          |  |\n"
          << "          |  |\n"
          << "   ______/____\\____\n"
          << "      " << executor.getName() << "\n";

  outfile.close();

  std::cout << "[ShrubberyCreationForm] " << this->getName() << " saved "
            << file_name << " file in the working directory!" << std::endl;
}
