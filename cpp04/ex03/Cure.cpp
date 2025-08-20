/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:51:24 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 15:52:12 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT false
# endif

# define COL	"\e[48;2;100;0;0;1m "
# define RES	" \e[0m"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Cure::Cure() : AMateria("cure") {
	if (DEBUG_PRINT)
		std::cout << COL "Cure" << RES << " default constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other._type) {
	if (DEBUG_PRINT)
		std::cout << COL "Cure" << RES << " copy constructor called" << std::endl;
}

// Default destructor
Cure::~Cure() {
	if (DEBUG_PRINT)
		std::cout << COL "Cure" << RES << " default destructor called" << std::endl;
}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator (Nothing to sopy)
Cure& Cure::operator=(const Cure& other) {
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/* Other functions */
/* ************************************************************************** */

// Clone overload functions
AMateria* Cure::clone() const {
	return (new Cure);
}

//Use functions
void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
