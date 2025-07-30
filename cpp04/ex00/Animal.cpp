/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:49:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 06:07:24 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Animal::Animal() {
	std::cout << GRN"Animal" << RES << " default constructor"  << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) {
	std::cout << GRN"Animal" << RES << " copy constructor called " << std::endl;
	*this = other;
}

// Default destructor
Animal::~Animal() {
	std::cout << RED"Animal" << RES << " destructor called" << std::endl;
}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
Animal& Animal::operator=(const Animal& other) {
	std::cout << BLU"Animal" << RES << " copy assignement operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */

//Type Getter 
std::string	Animal::getType(void) const {
	return (this->type);
}

//Animal make sound
void	Animal::makeSound(void) const {
	std::cout << "(The sound of silence)" << std::endl;
}
