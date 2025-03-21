/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:05:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/03/21 10:17:56 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"

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

void Phonebook::add_loop(void)
{
	std::string	name = "";
	std::string	surname = "";
	std::string	family_name = "";
	std::string	dark_secret = "";
	std::string	phone_number = "";

	while (name.empty() || is_only_spacer(name))
	{
		std::cout << PF_ADD << " [" << this->count % 8 + 1 << "] Firstname : ";
		if (!std::getline (std::cin, name))
			break;
	}
	while (surname.empty())
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Nickname : ";
		if (!std::getline (std::cin, surname))
			break;
	}
	while (family_name.empty())
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Lastname : ";
		if (!std::getline (std::cin, family_name))
			break;
	}
	while (dark_secret.empty())
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Darkest secret : ";
		if (!std::getline (std::cin, dark_secret))
			break;
	}
	while (phone_number.empty())
	{
		std::cout << PF_ADD  << " [" << this->count % 8 + 1 << "] Phone number : ";
		if (!std::getline (std::cin, phone_number))
			break;
	}
	this->contact[this->count % 8].set(name, surname, family_name, dark_secret, phone_number);
	this->count++;
}

void Phonebook::search_loop(void)
{
	std::string	str;
	int			i;

	if (this->count < 1)
			std::cout << P " No index registered ! Use Add tu create one. " R << std::endl;
	else
	{
		this->print();
		std::cout << PF_SEARCH << " by index : ";
		if (!std::getline (std::cin, str))
			return;
		i = std::atoi(str.c_str());
		if (i % 8 > this->count || i > 8  || i == 0 || str.empty())
			std::cout << PF_SEARCH << " Please enter a valid value." << std::endl;
		else
			this->contact[i % 8 - 1].print(str);
	}
}

void Phonebook::print(void)
{
	std::cout
		<< P "███████████████████████████████████████████████" R << std::endl
		<< P "█| Index    | Name     | Lastname | Nickname |█" R << std::endl
		<< P "███████████████████████████████████████████████" R << std::endl
		<< P "█╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋█" R << std::endl;
	for(int i = 0; i < 8 && i < this->count; i++)
	{
		std::cout
		<< P "█|" << std::setw(10) << i + 1
		<<   "|" << this->contact[i].data_ten_limit()
		<<   "|" << this->contact[i].data_ten_limit()
		<<   "|" << this->contact[i].data_ten_limit()
		<<   "|█" << R << std::endl
		<< P "█╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━╋█" R << std::endl;
	}
	std::cout
		<< P "███████████████████████████████████████████████" R << std::endl;
}
