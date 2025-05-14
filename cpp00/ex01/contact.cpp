/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:15:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/14 12:33:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
	return ;
}

void Contact::set(std::string name, std::string nickname, std::string family_name,
				 std::string dark_secret, std::string phone_number)
{
	this->name = name;
	this->family_name = family_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->dark_secret = dark_secret;
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
		<< " Firstname : " << this->name << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Lastname : " << this->family_name << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Nickname : " << this->nickname << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Phone number : " << this->phone_number << std::endl
		<< "\e[48;2;0;0;70;1m[" << i << "]\e[0m"
		<< " Darkest secret : " << this->dark_secret << std::endl;
}

std::string Contact::data_ten_limit(void)
{
	static int	arg = 0;
	int			i;
	std::string	str;

	if (arg % 3 == 0)
		str = this->name;
	else if (arg % 3 == 1)
		str = this->family_name;
	else if (arg % 3 == 2)
		str = this->nickname;
	arg++;
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
