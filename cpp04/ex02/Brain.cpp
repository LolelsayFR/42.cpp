/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 06:17:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/30 06:21:53 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Brain::Brain() {
	std::cout << GRN"Brain" << RES << " default constructor"  << std::endl;
}

// Copy constructor
Brain::Brain(const Brain& other) {
	std::cout << GRN"Brain" << RES << " copy constructor called " << std::endl;
	*this = other;
}

// Default destructor
Brain::~Brain() {
	std::cout << RED"Brain" << RES << " destructor called" << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
Brain& Brain::operator=(const Brain& other) {
	std::cout << BLU"Brain" << RES << " copy assignement operator called" << std::endl;
	for (int i = 0; i <= 100; i++)
		this->ideas[i] = other.ideas[i];
	return (*this);
}