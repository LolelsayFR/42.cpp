/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:05:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 10:08:06 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->isrunning = true;
	this->count = 0;
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

void Phonebook::AddLoop(void)
{
	std::string	Name = "";
	std::string	surname = "";
	std::string	LastName = "";
	std::string	DarkestSecret = "";
	std::string	PhoneNumber = "";

	while (Name.empty() || ::IsOnlySpacer(Name) == true)
	{
		std::cout << PF_ADD << " [" << this->count % 8 + 1 << "] Firstname : ";
		if (!std::getline (std::cin, Name))
			return;
	}
	while (surname.empty() || ::IsOnlySpacer(surname) == true)
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] NickName : ";
		if (!std::getline (std::cin, surname))
			return;
	}
	while (LastName.empty() || ::IsOnlySpacer(LastName) == true)
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Lastname : ";
		if (!std::getline (std::cin, LastName))
			return;
	}
	while (DarkestSecret.empty() || ::IsOnlySpacer(DarkestSecret) == true)
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Darkest secret : ";
		if (!std::getline (std::cin, DarkestSecret))
			return;
	}
	while (PhoneNumber.empty() || ::IsOnlySpacer(PhoneNumber) == true)
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Phone number : ";
		if (!std::getline (std::cin, PhoneNumber))
			return;
	}
	this->contact[this->count % 8].SetData(Name, surname, LastName, DarkestSecret, PhoneNumber);
	this->count++;
}

void Phonebook::SearchLoop(void)
{
	std::string	str;
	int			i;

	if (this->count < 1)
			std::cout << P " No index registered ! Use Add to create one. " R << std::endl;
	else
	{
		this->Print();
		std::cout << PF_SEARCH << " by index : ";
		if (!std::getline (std::cin, str))
			return;
		i = std::atoi(str.c_str());
		if (i % 9 > this->count || i > 9  || i == 0 || str.empty())
			std::cout << PF_SEARCH << " Please enter a valid value." << std::endl;
		else
			this->contact[i % 9 - 1].print(str);
	}
}

void Phonebook::Print(void)
{
	std::cout
		<< P "███████████████████████████████████████████████" R << std::endl
		<< P "█| Index    | Name     | Lastname | NickName |█" R << std::endl
		<< P "███████████████████████████████████████████████" R << std::endl
		<< P "█╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋█" R << std::endl;
	for(int i = 0; i < 8 && i < this->count; i++)
	{
		std::cout
		<< P "█|" << std::setw(10) << i + 1
		<<   "|" << this->contact[i].PrintData(0)
		<<   "|" << this->contact[i].PrintData(1)
		<<   "|" << this->contact[i].PrintData(2)
		<<   "|█" << R << std::endl
		<< P "█╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋█" R << std::endl;
	}
	std::cout
		<< P "███████████████████████████████████████████████" R << std::endl;
}
