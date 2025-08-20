/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:48:53 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 15:52:03 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT false
# endif


# define COL	"\e[48;2;70;70;170;1m "
# define RES	" \e[0m"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Ice::Ice() : AMateria("ice") {
	if (DEBUG_PRINT)
		std::cout << COL"Ice" << RES << " default constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other._type) {
	if (DEBUG_PRINT)
		std::cout << COL"Ice" << RES << " copy constructor called" << std::endl;
}

// Default destructor
Ice::~Ice() {
	if (DEBUG_PRINT)
		std::cout << COL"Ice" << RES << " default destructor called" << std::endl;
}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator (Nothing to sopy)
Ice& Ice::operator=(const Ice& other) {
	(void)other;
	return (*this);
}

/* ************************************************************************** */
/* Other functions */
/* ************************************************************************** */

// Clone overload functions
AMateria* Ice::clone() const {
	return (new Ice);
}

// Use function
void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
