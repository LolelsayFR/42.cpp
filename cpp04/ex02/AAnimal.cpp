/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:49:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 07:49:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
AAnimal::AAnimal() {
	std::cout << GRN"AAnimal" << RES << " default constructor"  << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) {
	std::cout << GRN"AAnimal" << RES << " copy constructor called " << std::endl;
	*this = other;
}

// Default destructor
AAnimal::~AAnimal() {
	std::cout << RED"AAnimal" << RES << " destructor called" << std::endl;
}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << BLU"AAnimal" << RES << " copy assignement operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */

//Type Getter 
std::string	AAnimal::getType(void) const {
	return (this->type);
}

//AAnimal make sound
void	AAnimal::makeSound(void) const {
	std::cout << "(The sound of silence)" << std::endl;
}
