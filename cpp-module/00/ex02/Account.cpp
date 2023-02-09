#include "Account.hpp"
#include <iostream>
#include <ctime>

/* Static variable initialization */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Member Functions */
std::string createTimestamp(void) {
  char buffer[20];

  std::time_t now = std::time(NULL);
  std::tm *timeinfo = std::localtime(&now);
  std::strftime(buffer, 20, "%Y%m%d_%H%M%S", timeinfo);
  return (buffer);
}

void Account::_displayTimestamp(void) {
  std::cout << "[" << createTimestamp() << "]"
            << " ";
}

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

int Account::checkAmount(void) const { return (_amount); }

void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";";
  std::cout << "total:" << getTotalAmount() << ";";
  std::cout << "deposits:" << getNbDeposits() << ";";
  std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << checkAmount() << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  int p_amount = checkAmount();

  _totalNbDeposits += 1;
  _totalAmount += deposit;
  _nbDeposits += 1;
  _amount += deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << checkAmount() << ";";
  std::cout << "nb_deposit:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  int p_amount = checkAmount();
  bool isAmountEnough;

  _displayTimestamp();
  if (p_amount - withdrawal < 0) {
    isAmountEnough = false;
  } else {
    isAmountEnough = true;
    _totalNbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _nbWithdrawals += 1;
    _amount -= withdrawal;
  }

  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << p_amount << ";";
  if (isAmountEnough) {
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_withdrawal:" << _nbWithdrawals << std::endl;
  } else {
    std::cout << "withdrawal:" << "refused" << std::endl;
  }

  return (isAmountEnough);
}

/* Constructor */
Account::Account(void) {}

Account::Account(int initial_deposit) {
  _displayTimestamp();
  _accountIndex = getNbAccounts();
  _nbAccounts += 1;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << checkAmount() << ";";
  std::cout << "created" << std::endl;
}

/* Destructor */
Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << checkAmount() << ";";
  std::cout << "closed" << std::endl;
}
