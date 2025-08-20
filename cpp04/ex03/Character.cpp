/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:55:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/20 15:54:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DEBUG_PRINT
#  define DEBUG_PRINT false
# endif

# include "Character.hpp"
# include <iostream>
# include <string>

# define COL	"\e[48;2;0;100;0;1m "
# define RES	" \e[0m"

/* ************************************************************************** */
/* All constructor and destructor */
/* ************************************************************************** */

// Default constructor
Character::Character() : _name("") {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " default constructor called" << std::endl;
	std::fill_n(this->_notEmptySlot, INV_SIZE, false);
}

// Copy constructor
Character::Character(const Character& other) {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " copy constructor called" << std::endl;
	*this = other;
}

// Name Assignement constructor
Character::Character(std::string name) : _name(name) {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " name assignement constructor called" << std::endl;	
	std::fill_n(this->_notEmptySlot, INV_SIZE, false);
}

// Default destructor
Character::~Character() {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " default destructor called" << std::endl;
	int i = 0;
	while (i < INV_SIZE) {
		if (this->_notEmptySlot[i] && this->_inventory[i] && this->_inventory[i]->isOnCharacter())
			delete this->_inventory[i++];
		else
			i++;
	}
}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
Character& Character::operator=(const Character& other) {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " copy operator called" << std::endl;
	std::fill_n(this->_notEmptySlot, INV_SIZE, false);
	this->_name = other._name;
	for (int i = 0; i < INV_SIZE; i++ ) {
		if (other._notEmptySlot[i] == true) {
			this->_inventory[i] = other._inventory[i]->clone();
			this->_inventory[i]->setOnCharacter();
			this->_notEmptySlot[i] = true;
		}
	}
	return (*this);
}

/* ************************************************************************** */
/* All interface functions */
/* ************************************************************************** */

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " equip function called" << std::endl;
	if (m == 0 || m->isOnCharacter() == true)
		return ;
	int i = 0;
	while (i < INV_SIZE){
		if (this->_notEmptySlot[i] == false)
			break ;
		else
			i++;
	}
	if (i < INV_SIZE) {
		this->_inventory[i] = m;
		this->_notEmptySlot[i] = true;
		m->setOnCharacter();
	}
}

void Character::unequip(int idx) {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " unequip function called" << std::endl;
	if (idx < 0 || idx >= INV_SIZE)
		return ;
	if (this->_notEmptySlot[idx] == false)
		return ;
	this->_notEmptySlot[idx] = false;
	this->_inventory[idx]->unsetOnCharacter();
}

void Character::use(int idx, ICharacter& target) {
	if (DEBUG_PRINT)
		std::cout << COL"Character" << RES << " use function called" << std::endl;
	if (idx < 0 || idx >= INV_SIZE)
		return ;
	if (this->_notEmptySlot[idx] == true)
		this->_inventory[idx]->use(target);
}
