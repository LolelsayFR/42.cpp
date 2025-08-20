/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:40:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 14:53:11 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT false
# endif

# define COL	"\e[48;2;100;100;0;1m "
# define RES	" \e[0m"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Copy constructor
AMateria::AMateria(const AMateria& other) : _onChar(false), _type(other.getType()) {
	if (DEBUG_PRINT)
		std::cout << COL"AMateria" << RES << " copy constructor called" << std::endl;
}

// Type constructor
AMateria::AMateria(std::string const & type) : _onChar(false), _type(type) {
	if (DEBUG_PRINT)
		std::cout << COL"AMateria" << RES << " Type asignation constructor called "<< std::endl;
}

// Default destructor
AMateria::~AMateria() {
	if (DEBUG_PRINT)
		std::cout << COL"AMateria" << RES << " default destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
AMateria& AMateria::operator=(const AMateria& other) {
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/* All other functions */
/* ************************************************************************** */

//Amateria getType
std::string const & AMateria::getType() const {
	return (this->_type);
}

//Amateria isOnCharacter
bool const & AMateria::isOnCharacter() const {
	return (this->_onChar);
}

//Amateria set on Character
void AMateria::setOnCharacter() {
	this->_onChar = true;
}

//Amateria set on Character
void AMateria::unsetOnCharacter() {
	this->_onChar = false;
}

//AMateria use functions
void AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " do nothing.." << std::endl;
}

