/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:58:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 15:00:17 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT false
# endif

# define COL	"\e[48;2;0;100;100;1m "
# define RES	" \e[0m"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
MateriaSource::MateriaSource() {
	if (DEBUG_PRINT)
		std::cout << COL"MateriaSource" << RES << " default constructor called" << std::endl;
	std::fill_n(this->_notEmptySlot, INV_SIZE, false);
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) {
	if (DEBUG_PRINT)
		std::cout << COL"MateriaSource" << RES << " copy constructor called" << std::endl;
	*this = other;
}

// Default destructor
MateriaSource::~MateriaSource() {
	if (DEBUG_PRINT)
		std::cout << COL"MateriaSource" << RES << " default destructor called" << std::endl;
	int i = 0;
	while (i < INV_SIZE)
		if (this->_notEmptySlot[i] && this->_inventory[i]->isOnCharacter() == false)
			delete this->_inventory[i++];
		else
			i++;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (DEBUG_PRINT)
		std::cout << COL"MateriaSource" << RES << " copy operator called" << std::endl;
	std::copy(other._notEmptySlot, other._notEmptySlot + INV_SIZE, this->_notEmptySlot);
	for (int i = 0; i < INV_SIZE; i++) {
		if (other._notEmptySlot[i] == true) {
			this->_inventory[i] = other._inventory[i]->clone();
			this->_notEmptySlot[i] = true;
		}
	}
	return (*this);
}


/* ************************************************************************** */
/* Interface functions */
/* ************************************************************************** */

void MateriaSource::learnMateria(AMateria* m) {
	if (DEBUG_PRINT)
		std::cout << COL"MateriaSource" << RES << " equip function called"<< m->getType() << std::endl;
	int i = 0;
	while (i < INV_SIZE) {
		if (this->_notEmptySlot[i] == false)
			break ;
		else
			i++;
	}
	if (i < INV_SIZE) {
		this->_inventory[i] = m;
		this->_notEmptySlot[i] = true;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < INV_SIZE; i++)
		if (this->_notEmptySlot[i] == true && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	return (0);
}
