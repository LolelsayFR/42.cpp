/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/28 16:53:21 by lolelsay         ###   ########.fr       */
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
	std::string name = "Robotomy request";
	
	
	Intern billy;
	AForm* form = billy.makeForm(name, target);
	std::cout << WHI"All execute test from the USER" << RES << std::endl;
	Bureaucrat user("USER", userGrade);
	std::cout << user << std::endl << *form  << std::endl;
	user.executeForm(*form);
	user.signForm(*form);
	std::cout << *form << std::endl;
	user.executeForm(*form);
	delete form;
	return (0);
}