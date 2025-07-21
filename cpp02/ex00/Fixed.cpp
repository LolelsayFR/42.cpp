/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:10:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/21 11:23:41 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* ************************************************************************** */
/* All constructors and the destructor*/
/* ************************************************************************** */

// Default constructor
Fixed::Fixed() : _number(0) {
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    this->_number = other.getRawBits();
}

//Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignement constructor called" << std::endl;
    this->_number = other.getRawBits();
    return (*this);
}


/* ************************************************************************** */
/* Getter and Setter */
/* ************************************************************************** */

//Getter for _number
int Fixed::getRawBits( void ) const {
    int const value = this->_number;
	std::cout << "getRawBits function called\n";
	return (value);
}

//Setter for _number
void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits function called\n";
    this->_number = raw;
}