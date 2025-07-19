/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:10:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/19 15:07:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_number = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i)
{
    this->_number = i;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float const f)
{
    this->_number = f;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_number = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignement constructor called" << std::endl;
    this->_number = other.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed)
{
    out << Fixed._number;
        //Fixed.toFloat();
    return out;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    int const value = this->_number;
	std::cout << "getRawBits function called\n";
	return (value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits function called\n";
    this->_number = raw;
}