/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 00:54:43 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 05:16:13 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
WrongCat::WrongCat() {
	std::cout << GRN"WrongCat" << RES << " default constructor"  << std::endl;
    this->type = "WrongCat";
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) {
    std::cout << GRN"WrongCat" << RES << " copy constructor called " << std::endl;
    *this = other;
}

// Default destructor
WrongCat::~WrongCat() {
    std::cout << RED"Dog" << RES << " destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << BLU"WrongCat" << RES << " copy assignement operator called" << std::endl;
    this->type = other.type;
    return (*this);
}

//WrongAnimal make sound
void	WrongCat::makeSound(void) const {
    std::cout << "Meow (But wrong)" << std::endl;
}
