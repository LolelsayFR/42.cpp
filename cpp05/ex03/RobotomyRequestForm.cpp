/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:44:10 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 12:28:38 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

# define TO_SIGN_GRADE 72
# define TO_EXEC_GRADE 45

/* ************************************************************************** */
/* Constructors and destructor */
/* ************************************************************************** */

//Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", TO_EXEC_GRADE, TO_SIGN_GRADE),  _target("Nowhere") {}

//Name assignation constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", TO_EXEC_GRADE, TO_SIGN_GRADE), _target(target) {}

//Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other) :  AForm(other.getName(), other.getGradeToExecute(), other.getGradeToSign()) {
	this->operator=(other);
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {}

/* ************************************************************************** */
/* Operator overload */
/* ************************************************************************** */

//Copy operator
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
	if (other.getIsSigned())
		this->setIsSigned();
	this->_target = other._target;
	return (*this);
}

/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

//Exec function
void RobotomyRequestForm::doSomething(void) const {
	std::cout << "Vzzzzzz... DRILL DRILL DRIIILLL..." << std::endl;
	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);
    std::srand(datetime.tm_sec);
    const int random_value = std::rand() % 2;
	if (random_value == 0)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}

/* ************************************************************************** */
/* end of file */
/* ************************************************************************** */