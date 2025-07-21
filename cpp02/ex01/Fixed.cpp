/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:10:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:21 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Fixed::Fixed() : _number(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Int arg constructor
Fixed::Fixed(int const i) : _number(i << this->_nBits) {
	std::cout << "Default constructor called" << std::endl;
}

//Float arg constructor
Fixed::Fixed(float const f) : _number(roundf(f * (1 << this->_nBits))) {
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

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& Fixed) {
	out << Fixed.toFloat();
	return out;
}


/* ************************************************************************** */
/* Getter and Setter */
/* ************************************************************************** */

//Getter for _number
int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits function called\n";
	return (this->_number);
}

//Setter for _number
void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits function called\n";
	this->_number = raw;
}

/* ************************************************************************** */
/* Convert and get value */
/* ************************************************************************** */

//Return float
float	Fixed::toFloat( void ) const {
	std::cout << std::endl << "toFloat call" << std::endl;
	return (this->_number / (1 << this->_nBits));
}

//Return int
int		Fixed::toInt( void ) const {
	return (this->_number >> this->_nBits);
}