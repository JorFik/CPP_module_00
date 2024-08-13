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

