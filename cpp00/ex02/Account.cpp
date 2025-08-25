#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:"
		      << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:";
	std::cout << getNbAccounts();
	std::cout << ";total:";
	std::cout << getTotalAmount();
	std::cout << ";deposits:";
	std::cout << getNbDeposits();
	std::cout << ";withdrawals:";
	std::cout << getNbWithdrawals() << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
	std::cout << "["
		      << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:"
		      << _accountIndex
			  << ";amount:"
			  << _amount
			  << ";deposits:"
			  << _nbDeposits
			  << ";withdrawals:"
			  << _nbWithdrawals
			  << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"
		      << _accountIndex
			  << ";p_amount:"
			  << _amount
			  << ";deposit:"
			  << deposit
			  << ";amount:";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << _amount
		      << ";nb_deposits:"
			  << _nbDeposits
			  << std::endl;
}

bool	Account::makeWithdrawal(int withdrawals)
{
	_displayTimestamp();
	std::cout << "index:"
		      << _accountIndex
			  << ";p_amount:"
			  << _amount
			  << ";withdrawal:";
	if (withdrawals > _amount)
	{
		std::cout << "refused\n";
		return (false);
	}
	_amount -= withdrawals;
	_totalAmount -= withdrawals;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawals
		      << ";amount:"
			  << _amount
			  << ";nb_withdrawals:"
			  << _nbWithdrawals;	
	std::cout << std::endl;
	return (true);
}
