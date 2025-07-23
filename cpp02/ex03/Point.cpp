/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 06:42:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/23 07:34:21 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* ************************************************************************** */
/* All constructors and destructors */
/* ************************************************************************** */

Point::Point() : _x(0), _y(0) {
	// std::cout << "Default constructor called (Point)" << std::endl;
}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {
	// std::cout << "'Two float' constructor called (Point)" << std::endl;
}

Point::Point(const Point& other) {
	*this = other;
	// std::cout << "Copy constructor called (Point)" << std::endl;
}

// Destructor
Point::~Point() {
	// std::cout << "Destructor called (Point)" << std::endl;
}


/* ************************************************************************** */
/* Getter and Setter */
/* ************************************************************************** */

const Fixed& Point::getX(void) const {
	// std::cout << "GetX member function called (Point)" << std::endl;
	return (this->_x);
}

const Fixed& Point::getY(void) const {
	// std::cout << "GetY member function called (Point)" << std::endl;
	return (this->_y);
}

/* ************************************************************************** */
/* All operators overload */
/* ************************************************************************** */

// Copy operator (Cant replace const)
Point& Point::operator=(const Point& other) {
	// std::cout << "Copy operator called (point)" << std::endl;
	(void) other;
	return (*this);
}
