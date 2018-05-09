/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <lkaser@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 20:18:09 by lkaser            #+#    #+#             */
/*   Updated: 2018/01/08 21:13:34 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.class.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "closed" << std::endl;
}

void		Account::_displayTimestamp(void)
{
	char		formatted_time[100];
	time_t		gmt_time = time(0);
	struct tm	*local_time = localtime(&gmt_time);
	strftime(formatted_time, 100, "[%Y%d%m_%H%M%S] ", local_time);
	std::cout << formatted_time;
}

void		Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ';'
		<< "total:" << _totalAmount << ';'
		<< "deposits:" << _totalNbDeposits << ';'
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void		Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "amount:" << _amount << ';'
		<< "deposits:" << _nbDeposits << ';'
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "deposit:" << deposit << ';';
	_nbDeposits += 1;
	_amount += deposit;
	std::cout
		<< "amount:" << _amount << ';'
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (_amount < withdrawal) {
		std::cout
			<< "index:" << _accountIndex << ';'
			<< "p_amount:" << _amount << ';'
			<< "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	std::cout
		<< "index:" << _accountIndex << ';'
		<< "p_amount:" << _amount << ';'
		<< "withdrawal:" << withdrawal << ';'
		<< "amount:" << _amount << ';'
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}
