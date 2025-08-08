/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:49:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/08 06:40:44 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
WrongAnimal::WrongAnimal() {
	std::cout << GRN"WrongAnimal" << RES << " default constructor"  << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << GRN"WrongAnimal" << RES << " copy constructor called " << std::endl;
    *this = other;
}

// Default destructor
WrongAnimal::~WrongAnimal() {
    std::cout << RED"WrongAnimal" << RES << " destructor called" << std::endl;
}

/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << BLU"WrongAnimal" << RES << " copy assignement operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

/* ************************************************************************** */
/* Member functions */
/* ************************************************************************** */

//Type Getter 
std::string	WrongAnimal::getType(void) const {
    return (this->type);
}

//WrongAnimal make sound
void	WrongAnimal::makeSound(void) const {
    std::cout << "(The sound of silence but wrong)" << std::endl;
}
