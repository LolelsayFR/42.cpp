/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:54:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/08 08:21:24 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Cat::Cat() {
	std::cout << GRN"Cat" << RES << " default constructor"  << std::endl;
    this->type = "Cat";
}

// Copy constructor
Cat::Cat(const Cat& other) {
    std::cout << GRN"Cat" << RES << " copy constructor called " << std::endl;
    *this = other;
}

// Default destructor
Cat::~Cat() {
    std::cout << RED"Cat" << RES << " destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
Cat& Cat::operator=(const Cat& other) {
    std::cout << BLU"Cat" << RES << " copy assignement operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

//Animal make sound
void	Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
