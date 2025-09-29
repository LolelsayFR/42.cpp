/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:44:10 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 13:50:19 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* Constructors and destructor */
/* ************************************************************************** */

//Default constructor
Form::Form(void) : _name("Basic Form"), _gradeToExecute(150), _gradeToSign(150), _isSigned(false) {}

//Asignation constructor
Form::Form(const std::string name, const int gts, const int gte) : _name(name), _gradeToExecute(gte), _gradeToSign(gts), _isSigned(false)  {
	if (gts < 1 || gte < 1)
		throw (Form::GradeTooHighException());
	if (gts > 150 || gte > 150)
		throw (Form::GradeTooLowException());
} 

//Copy constructor
Form::Form(Form& other) : _name(other._name), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign) {
	this->operator=(other);
}

//Destructor
Form::~Form(void) {}

/* ************************************************************************** */
/* Operator overload */
/* ************************************************************************** */

//Copy operator
Form& Form::operator=(Form& other) {
	this->_isSigned = other._isSigned;
	return (*this);
}

//Ostream insertion operator
std::ostream& operator<<(std::ostream& o, const Form& form) {
	o << "\nForm info : " << &form << std::endl;
	o << "\tName = " << form.getName() << std::endl;
	o << "\tGrade to sign = " << form.getGradeToSign() << std::endl;
	o << "\tGrade to execute = " << form.getGradeToExecute() << std::endl;
	o << "\tIs signed = " << form.getIsSigned() << std::endl;
	return (o);
}

/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

//Name getter
std::string Form::getName(void) const {
	return (this->_name);
}

//Grade to sigm getter
int Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

//Grade to execute getter
int Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

//Is signed getter
bool Form::getIsSigned(void) const {
	return (this->_isSigned);
}

//Sign form member function
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (Form::GradeTooLowException());
	else
		this->_isSigned = true;
}

/* ************************************************************************** */
/* exceptions functions */
/* ************************************************************************** */

//High grade exception
const char* Form::GradeTooHighException::what(void) const throw() {
	return ("Form Error : Grade is too high !");
}

//Low grade exception
const char* Form::GradeTooLowException::what(void) const throw() {
	return ("Form Error : Grade is too low !");
}

/* ************************************************************************** */
/* end of file */
/* ************************************************************************** */