/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:55:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 05:16:23 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
WrongDog::WrongDog() {
	std::cout << GRN"WrongDog" << RES << " default constructor"  << std::endl;
    this->type = "WrongDog";
}

// Copy constructor
WrongDog::WrongDog(const WrongDog& other) {
    std::cout << GRN"WrongDog" << RES << " copy constructor called " << std::endl;
    *this = other;
}

// Default destructor
WrongDog::~WrongDog() {
    std::cout << RED"WrongDog" << RES << " destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
WrongDog& WrongDog::operator=(const WrongDog& other) {
    std::cout << BLU"WrongDog" << RES << " copy assignement operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

//WrongAnimal make sound
void	WrongDog::makeSound(void) const {
    std::cout << "BARK BARK (But wrong)" << std::endl;
}
