/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:34:11 by lolelsay          #+#    #+#             */
/*   Updated: 2025/10/22 13:00:22 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* All constructors and destructor */
/* ************************************************************************** */

//Default constructor
Intern::Intern(void) {}

//Copy constructor
Intern::Intern(Intern& other) {
	(void)other;
}

//Destructor
Intern::~Intern(void) {}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

Intern& Intern::operator=(Intern& other) {
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

static AForm* makePresidentialForm(std::string target)	{	return (new PresidentialPardonForm(target));	}
static AForm* makeRobotForm(std::string target)			{	return (new RobotomyRequestForm(target));		}
static AForm* makeShrubberyForm(std::string target) 	{	return (new ShrubberyCreationForm(target));		}

AForm* Intern::makeForm(std::string name, std::string target) const{
	int i = 0;
	std::string formName[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	AForm* (*func[3])(std::string target) = {
		&makePresidentialForm,
		&makeRobotForm,
		&makeShrubberyForm
	};
	while (i < 3 && name != formName[i])
		i++;
	if (i >= 3)
		throw(Intern::CantMakeFormException());
	return (func[i](target));
}

/* ************************************************************************** */
/* All exceptions */
/* ************************************************************************** */

//Make form exception
const char* Intern::CantMakeFormException::what(void) const throw(){
	return ("Error : Could not find an appropriate form to create!");
}

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */
