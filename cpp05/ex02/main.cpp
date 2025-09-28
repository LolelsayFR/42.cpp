/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/28 15:28:01 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define WHI	"\e[1;38;5;0;107m "
#define RES	" \e[0m"

int	main(int ac, char **av) {
	int userGrade = 1;
	if (ac == 2)
		userGrade = std::atoi(av[1]);
	{
		std::cout << WHI"All PresidentialPardonForm constructor's test" << RES << std::endl;
		PresidentialPardonForm base;
		PresidentialPardonForm assign("White house");
		PresidentialPardonForm copy(base);
		std::cout << base << assign << copy << std::endl;
	}
	{
		std::cout << WHI"All RobotomyRequestForm constructor's test" << RES << std::endl;
		RobotomyRequestForm base;
		RobotomyRequestForm assign("Plankton");
		RobotomyRequestForm copy(base);
		std::cout << base << assign << copy << std::endl;
	}
	{
		std::cout << WHI"All ShrubberyCreationForm constructor's test" << RES << std::endl;
		ShrubberyCreationForm base;
		ShrubberyCreationForm assign("Mojo");
		ShrubberyCreationForm copy(base);
		std::cout << base << assign << copy << std::endl;
	}
	std::cout << WHI"All execute test from the USER (Add grade in argument, default is 1)" << RES << std::endl;
	Bureaucrat user("USER", userGrade);
	PresidentialPardonForm pardon("White house");
	RobotomyRequestForm robot("Plankton");
	ShrubberyCreationForm tree("Mojo");
	std::cout << user << std::endl << pardon << robot << tree << std::endl;
	user.executeForm(pardon);
	user.executeForm(robot);
	user.executeForm(tree);
	user.signForm(pardon);
	user.signForm(robot);
	user.signForm(tree);
	std::cout << pardon << robot << tree << std::endl;
	user.executeForm(pardon);
	user.executeForm(robot);
	user.executeForm(tree);
	return (0);
}