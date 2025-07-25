/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:10:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 03:50:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Fixed::Fixed() : _rawBits(0) {
	// std::cout << "Default constructor called" << std::endl;
}

// Int arg constructor
Fixed::Fixed(int const i) : _rawBits(i << this->_nBits) {
	// std::cout << "Default constructor called" << std::endl;
}

//Float arg constructor
Fixed::Fixed(float const f) : _rawBits(roundf(f * (1 << this->_nBits))) {
	// std::cout << "Default constructor called" << std::endl;
}

//Copy constructor
Fixed::Fixed(const Fixed& other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

//Destructor
Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& Fixed) {
	out << Fixed.toFloat();
	return (out);
}

// Copy operator
Fixed& Fixed::operator=(const Fixed& other) {
	// std::cout << "Copy operator called" << std::endl;
	this->_rawBits = other.getRawBits();
	return (*this);
}

// Arithmétiqual operator
Fixed Fixed::operator+(const Fixed& other) {
	// std::cout << "+ operator called" << std::endl;
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) {
	// std::cout << "- operator called" << std::endl;
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) {
	// std::cout << "* operator called" << std::endl;
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) {
	// std::cout << "/ operator called" << std::endl;
	return (Fixed(this->toFloat() / other.toFloat()));
}

// Comparaison operator
bool	Fixed::operator==(const Fixed& other) {
	// std::cout << "== operator called" << std::endl;
	if (this->toFloat() == other.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) {
	// std::cout << "!= operator called" << std::endl;
	if (this->toFloat() != other.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) {
	// std::cout << "< operator called" << std::endl;
	if (this->toFloat() < other.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>(const Fixed& other) {
	// std::cout << "> operator called" << std::endl;
	if (this->toFloat() > other.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) {
	// std::cout << "<= operator called" << std::endl;
	if (this->toFloat() <= other.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) {
	// std::cout << ">= operator called" << std::endl;
	if (this->toFloat() >= other.toFloat())
		return (true);
	return (false);
}



// For increment and decrement operator see this : https://learn.microsoft.com/fr-fr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
// Prefix increment operator.
Fixed& Fixed::operator++() {
	this->_rawBits++;
	return (*this);
}

// Postfix increment operator.
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++*this;
	return (temp);
}

// Prefix decrement operator.
Fixed& Fixed::operator--() {
	this->_rawBits--;
	return (*this);
}

// Postfix decrement operator.
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--*this;
	return (temp);
}

/* ************************************************************************** */
/* Getter and Setter */
/* ************************************************************************** */

//Getter for _rawBits
int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits function member called\n";
	return (this->_rawBits);
}

//Setter for _rawBits
void Fixed::setRawBits( int const raw ) {
	// std::cout << "setRawBits function member called\n";
	this->_rawBits = raw;
}

/* ************************************************************************** */
/* Convert and get value */
/* ************************************************************************** */

//Return float value
float	Fixed::toFloat(void)const {
	return ((float)this->_rawBits / (1 << this->_nBits));
}

//Return int value
int	Fixed::toInt(void)const {
	return (this->_rawBits >> this->_nBits);
}

/* ************************************************************************** */
/* Min and Max member functions */
/* ************************************************************************** */

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	if (Fixed(a) < Fixed(b))
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (Fixed(a) > Fixed(b))
		return (a);
	return (b);
}
