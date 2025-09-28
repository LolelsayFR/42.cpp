/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:34:11 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 16:50:46 by lolelsay         ###   ########.fr       */
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
	if (name == "Presidential Pardon" || name == "Presidential pardon")
		return (new PresidentialPardonForm(target));
	if (name == "Robotomy Request" || name == "Robotomy request")
		return (new RobotomyRequestForm(target));
	if (name == "Shrubbery Creation" || name == "Shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (NULL);
}

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */