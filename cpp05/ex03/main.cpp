/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/13 12:54:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define WHI	"\e[1;38;5;0;107m "
#define RES	" \e[0m"

int	main(void) {
	int userGrade = 1;
	std::string target = "Lehon Smuk";
	std::string name = "robotomy request";
	AForm* form = NULL;
	try {
		Intern billy;
		form = billy.makeForm(name, target);
		std::cout << WHI"All execute test from the USER" << RES << std::endl;
		
		try {
			Bureaucrat user("USER", userGrade);
			std::cout << user << std::endl << *form  << std::endl;
			try {
				user.executeForm(*form);
			}
			catch (std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			user.signForm(*form);
			std::cout << *form << std::endl;
			user.executeForm(*form);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	if (form != NULL)
		delete form;	
	return (0);
}