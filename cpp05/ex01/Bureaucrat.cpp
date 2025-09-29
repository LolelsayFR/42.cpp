/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 06:57:46 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/28 14:47:08 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* Constructor and destructor */
/* ************************************************************************** */

//Default constructor
Bureaucrat::Bureaucrat(void) : _name("John Doe"), _grade(150) {}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

//All assignation operator
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

//Default destructor
Bureaucrat::~Bureaucrat(void) {}

/* ************************************************************************** */
/* Operator overload */
/* ************************************************************************** */

//Assignation operator
Bureaucrat& Bureaucrat::operator=(Bureaucrat& other) {
	this->_grade = other._grade;
	return (*this);
}

//decrement the bureaucrat’s grade
void Bureaucrat::operator++(void) {
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

//increment the bureaucrat’s grade
void Bureaucrat::operator--(void) {
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

//Ostream insertion operator
std::ostream& operator<<(std::ostream& o, Bureaucrat& other) {
	o << other.getName() <<", bureaucrat grade "<< other.getGrade();
	return (o);
}

/* ************************************************************************** */
/* Other member functions */
/* ************************************************************************** */

//Name getter
const std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

//Grade getter
int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::signForm(Form& form) {
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	form.beSigned(*this);
	std::cout << *this << " sign " << form.getName() << std::endl;
}

/* ************************************************************************** */
/* exceptions */
/* ************************************************************************** */

//High grade exception
const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat Error : Grade is too high !");
}

//Low grade exception
const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat Error : Grade is too low !");
}

/* ************************************************************************** */
/* end of file */
/* ************************************************************************** */