/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:10:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/23 05:02:29 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* ************************************************************************** */
/* All constructors and the destructor*/
/* ************************************************************************** */

// Default constructor
Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
	this->operator=(other);
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
    std::cout << "Copy assignement operator called" << std::endl;
    this->_rawBits = other.getRawBits();
    return (*this);
}


/* ************************************************************************** */
/* Getter and Setter */
/* ************************************************************************** */

//Getter for _rawBits
int Fixed::getRawBits( void ) const {
    int const value = this->_rawBits;
	std::cout << "getRawBits member function called\n";
	return (value);
}

//Setter for _rawBits
void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called\n";
    this->_rawBits = raw;
}