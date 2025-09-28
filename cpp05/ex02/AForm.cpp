/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:44:10 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 11:59:38 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/* Constructors and destructor */
/* ************************************************************************** */

//Default constructor
AForm::AForm(void) : _name("Basic AForm"), _gradeToExecute(150), _gradeToSign(150), _isSigned(false) {}

//Asignation constructor
AForm::AForm(const std::string name, const int gts, const int gte) : _name(name), _gradeToExecute(gte), _gradeToSign(gts), _isSigned(false)  {
	try {
		if (gts < 1 || gte < 1)
			throw (AForm::GradeTooHighException());
		if (gts > 150 || gte > 150)
			throw (AForm::GradeTooLowException());
	}
	catch (std::exception& e) {
		std::cout << "Constructor : " << e.what() << std::endl;
	}
} 

//Copy constructor
AForm::AForm(AForm& other) : _name(other._name), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign) {
	this->operator=(other);
}

//Destructor
AForm::~AForm(void) {}

/* ************************************************************************** */
/* Operator overload */
/* ************************************************************************** */

//Copy operator
AForm& AForm::operator=(AForm& other) {
	this->_isSigned = other._isSigned;
	return (*this);
}

//Ostream insertion operator
std::ostream& operator<<(std::ostream& o, const AForm& AForm) {
	o << "\nForm info : " << &AForm << std::endl;
	o << "\tName = " << AForm.getName() << std::endl;
	o << "\tGrade to sign = " << AForm.getGradeToSign() << std::endl;
	o << "\tGrade to execute = " << AForm.getGradeToExecute() << std::endl;
	o << "\tIs signed = " << AForm.getIsSigned() << std::endl;
	return (o);
}

/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

//Name getter
std::string AForm::getName(void) const {
	return (this->_name);
}

//Grade to sigm getter
int AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}

//Grade to execute getter
int AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}

//Is signed getter
bool AForm::getIsSigned(void) const {
	return (this->_isSigned);
}

//Is signed setter
void AForm::setIsSigned(void) {
	this->_isSigned = true;
}

//Sign form member function
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw (AForm::GradeTooLowException());
	else
		this->_isSigned = true;
}

//Execute form
void AForm::execute(Bureaucrat const & executor) const {
	if (!this->_isSigned || executor.getGrade() > this->_gradeToExecute)
		throw (AForm::CantExecException());
	else
		this->doSomething();
}

/* ************************************************************************** */
/* exceptions functions */
/* ************************************************************************** */

//High grade exception
const char* AForm::GradeTooHighException::what(void) const throw() {
	return ("Form Error : Grade is too high !");
}

//Low grade exception
const char* AForm::GradeTooLowException::what(void) const throw() {
	return ("Form Error : Grade is too low !");
}

//Cant exec exception
const char* AForm::CantExecException::what() const throw() {
	return ("Form Exec error : The grade is too low to be executed and/or the form is not signed.");
}

/* ************************************************************************** */
/* end of file */
/* ************************************************************************** */