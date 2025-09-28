/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:44:10 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 14:51:55 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

# define TO_SIGN_GRADE 25
# define TO_EXEC_GRADE 5

/* ************************************************************************** */
/* Constructors and destructor */
/* ************************************************************************** */

//Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", TO_EXEC_GRADE, TO_SIGN_GRADE),  _target("Nowhere") {}

//Name assignation constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", TO_EXEC_GRADE, TO_SIGN_GRADE), _target(target) {}

//Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& other) :  AForm(other.getName(), other.getGradeToExecute(), other.getGradeToSign()) {
	this->operator=(other);
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {}

/* ************************************************************************** */
/* Operator overload */
/* ************************************************************************** */

//Copy operator
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other) {
	if (other.getIsSigned())
		this->setIsSigned();
	this->_target = other._target;
	return (*this);
}

/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

//Exec function
void PresidentialPardonForm::doSomething(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/* ************************************************************************** */
/* end of file */
/* ************************************************************************** */