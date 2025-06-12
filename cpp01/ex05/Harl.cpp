/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 02:18:25 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/12 05:16:06 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


Harl::Harl()
{
	std::cout 	<< "\n\e[38;2;255;255;255m\e[48;2;0;100;0m"
				<< " Welcome HARL \e[0m" << std::endl;
}

Harl::~Harl()
{
	std::cout 	<< "\e[38;2;255;255;255m\e[48;2;100;0;0m"
				<< " Goodbye HARL \e[0m\n" << std::endl;
}

void Harl::complain( std::string level )
{
	int	i;
	const std::string levelsStr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	i = 0;
	while (i < 4 && level.compare(levelsStr[i]))
		i++;
	(this->*func[i])();
}

void Harl::debug( void )
{
	std::cout	<< "DEBUG level:\n"
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
				<< "I really do!"
				<< std::endl;
}

void Harl::info( void )
{
	std::cout	<< "INFO level:\n"
				<< "I cannot believe adding extra bacon costs more money.\n"
				<< "You didn’t put enough bacon in my burger\n"
				<< "If you did, I wouldn’t be asking for more!"
				<< std::endl;
}

void Harl::warning( void )
{
	std::cout	<< "WARNING level:\n"
				<< "I think I deserve to have some extra bacon for free.\n"
				<< "I’ve been coming for years, whereas you started working here just last month."
				<< std::endl;
}

void Harl::error( void )
{
	std::cout	<< "ERROR level:\n"
				<< "This is unacceptable!\n"
				<< "I want to speak to the manager now."
				<< std::endl;
}
