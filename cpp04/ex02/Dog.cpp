/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:55:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 06:56:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Dog::Dog() {
	std::cout << GRN"Dog" << RES << " default constructor"  << std::endl;
    this->type = "Dog";
    this->_brain = new Brain;
}

// Copy constructor
Dog::Dog(const Dog& other) {
    std::cout << GRN"Dog" << RES << " copy constructor called " << std::endl;
    *this = other;
}

// Default destructor
Dog::~Dog() {
    std::cout << RED"Dog" << RES << " destructor called" << std::endl;
    delete this->_brain;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
Dog& Dog::operator=(const Dog& other) {
    std::cout << BLU"Dog" << RES << " copy assignement operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

//Animal make sound
void	Dog::makeSound(void) const {
	std::cout << "BARK BARK" << std::endl;
}