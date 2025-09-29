/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:34:11 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/29 09:57:13 by emaillet         ###   ########.fr       */
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

AForm* Intern::makeForm(std::string name, std::string target) const{
	if (name == "presidential pardon")
		return (new PresidentialPardonForm(target));
	if (name == "robotomy request")
		return (new RobotomyRequestForm(target));
	if (name == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	throw(Intern::CantMakeFormException());
	return (NULL);
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