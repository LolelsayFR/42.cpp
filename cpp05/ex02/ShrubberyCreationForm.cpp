/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 10:44:10 by lolelsay          #+#    #+#             */
/*   Updated: 2025/09/28 12:28:38 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

# define TO_SIGN_GRADE 145
# define TO_EXEC_GRADE 137
# define SUFFIX "_shrubbery"
#define ASCII_TREE0 "       _-_"
#define ASCII_TREE1 "    /~~   ~~\\"
#define ASCII_TREE2 " /~~         ~~\\"
#define ASCII_TREE3 "{               }"
#define ASCII_TREE4 " \\  _-     -_  /"
#define ASCII_TREE5 "   ~  \\\\ //  ~"
#define ASCII_TREE6 "_- -   | | _- _"
#define ASCII_TREE7 "  _ -  | |   -_"
#define ASCII_TREE8 "      // \\\\"
#define ASCII_TREE9 "Yes, this is a tree"

/* ************************************************************************** */
/* Constructors and destructor */
/* ************************************************************************** */

//Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) :  AForm("ShrubberyCreationForm", TO_EXEC_GRADE, TO_SIGN_GRADE), _target("Nowhere") {}

//Name assignation constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", TO_EXEC_GRADE, TO_SIGN_GRADE), _target(target){}

//Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) :  AForm(other.getName(), other.getGradeToExecute(), other.getGradeToSign()) {
	this->operator=(other);
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

/* ************************************************************************** */
/* Operator overload */
/* ************************************************************************** */

//Copy operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
	if (other.getIsSigned())
		this->setIsSigned();
	this->_target = other._target;
	return (*this);
}

/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

//Exec function
void ShrubberyCreationForm::doSomething(void) const {
	std::string myNewFileName = this->_target + SUFFIX;
	std::ofstream myNewFile(myNewFileName.c_str());
	if (myNewFile.is_open())
	{
		myNewFile << ASCII_TREE0 << std::endl;
		myNewFile << ASCII_TREE1 << std::endl;
		myNewFile << ASCII_TREE2 << std::endl;
		myNewFile << ASCII_TREE3 << std::endl;
		myNewFile << ASCII_TREE4 << std::endl;
		myNewFile << ASCII_TREE5 << std::endl;
		myNewFile << ASCII_TREE6 << std::endl;
		myNewFile << ASCII_TREE7 << std::endl;
		myNewFile << ASCII_TREE8 << std::endl;
		myNewFile << ASCII_TREE9 << std::endl;	
		myNewFile.close();
	}
}

/* ************************************************************************** */
/* end of file */
/* ************************************************************************** */