/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 20:47:40 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/13 17:48:59 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
int	Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;

void	Account::_displayTimestamp( void )
{
	char				time_stamp[42];
	const std::time_t	now = std::time(NULL);
	const std::tm		*local_now = std::localtime(&now);

	std::strftime(time_stamp, sizeof(time_stamp), "[%Y%m%d_%H%M%S] ", local_now);
}

void	print_in_colums(std::string str, unsigned char column_separator)
{
	std::cout << str << column_separator << std::flush;
}

Account::Account( int initial_deposit ) : _amount( initial_deposit )
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	print_in_colums("index", ':');
	print_in_colums(std::to_string(_accountIndex), ';');
	print_in_colums("amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	print_in_colums("index", ':');
	print_in_colums(std::to_string(_accountIndex), ';');
	print_in_colums("amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	print_in_colums("accounts", ':');
	print_in_colums(std::to_string(_nbAccounts), ';');
	print_in_colums("total", ':');
	print_in_colums(std::to_string(_totalAmount), ';');
	print_in_colums("deposits", ':');
	print_in_colums(std::to_string(_totalNbDeposits), ';');
	std::cout << "withdrawals" << std::to_string(_totalNbWithdrawals) << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	print_in_colums("index", ':');
	print_in_colums(std::to_string(_accountIndex), ';');
	print_in_colums("amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	print_in_colums("deposits", ':');
	print_in_colums(std::to_string(_nbDeposits), ';');
	print_in_colums("withdrawals", ':');
	print_in_colums(std::to_string(_nbWithdrawals), '\n');
	std::cout << std::flush;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	print_in_colums("index", ':');
	print_in_colums(std::to_string(_accountIndex), ';');
	print_in_colums("p_amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	print_in_colums("deposit", ':');
	print_in_colums(std::to_string(deposit), ';');
	_amount += deposit;
	_totalAmount += deposit;
	++_nbDeposits;
	++_totalNbDeposits;
	print_in_colums("amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	print_in_colums("nb_deposits", ':');
	print_in_colums(std::to_string(_nbDeposits), '\n');
	std::cout << std::flush;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	print_in_colums("index", ':');
	print_in_colums(std::to_string(_accountIndex), ';');
	print_in_colums("p_amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	print_in_colums("withdrawal", ':');
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	print_in_colums(std::to_string(withdrawal), ';');
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_nbWithdrawals;
	++_totalNbWithdrawals;
	print_in_colums("amount", ':');
	print_in_colums(std::to_string(_amount), ';');
	print_in_colums("nb_withdrawals", ':');
	print_in_colums(std::to_string(_nbWithdrawals), '\n');
	std::cout << std::flush;
	return (true);
}

