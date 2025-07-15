/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:15:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 10:52:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
	return ;
}

static std::string SpacersTrim(std::string str)
{
	int start = 0;
	int end = str.length() - 1;

	while (isspace(str[start]))
		start++;
	while (isspace(str[end]))
		end--;
	return (str.substr(start, end + 1 - start));
}

void Contact::SetData(std::string Name, std::string NickName, std::string LastName,
				 std::string DarkestSecret, std::string PhoneNumber)
{
	this->Name = SpacersTrim(Name);
	this->LastName = SpacersTrim(LastName);
	this->NickName = SpacersTrim(NickName);
	this->PhoneNumber = SpacersTrim(PhoneNumber);
	this->DarkestSecret = SpacersTrim(DarkestSecret);
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::print(std::string i)
{
	std::cout
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Firstname : " << this->Name << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Lastname : " << this->LastName << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " NickName : " << this->NickName << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Phone number : " << this->PhoneNumber << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Darkest secret : " << this->DarkestSecret << std::endl;
}

std::string Contact::PrintData(int arg)
{
	int			i;
	std::string	str;

	if (arg == 0)
		str = this->Name;
	else if (arg == 1)
		str = this->LastName;
	else if (arg == 2)
		str = this->NickName;
	i = strlen(str.c_str());
	if (i < 10)
		std::cout << std::setw(10) << str;
	else if (i == 10)
		std::cout << str;
	else if (i > 10)
		std::cout << str.substr(0, 9) << ".";
	if (arg == 3)
		arg = 0;
	return ("");
}
