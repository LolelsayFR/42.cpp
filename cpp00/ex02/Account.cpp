/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:44:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/14 20:46:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	char output[50];

	strftime(output, 50, "[%Y%m%d_%H%M%S] ", &datetime);
	std::cout << output;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";" 
				<< "amount:" << this->_amount << ";"
				<< "created"
				<< std::endl;
	_nbAccounts++;
	return ;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";" 
				<< "amount:" << this->_amount << ";"
				<< "closed"
				<< std::endl;
	return ;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";" 
				<< "p_amount:" << this->_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount + deposit << ";"
				<< "nb_deposits:" << this->_nbDeposits << ";"
				<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";" 
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:" << withdrawal << ";"
				<< "amount:" << this->_amount - withdrawal << ";"
				<< "nb_withdrawals:" << this->_nbDeposits << ";"
				<< std::endl;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	return (true);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";" 
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawal:" << _totalNbWithdrawals << ";"
				<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";" 
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << ";"
				<< std::endl;
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}