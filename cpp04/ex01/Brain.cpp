/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 06:17:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/18 12:12:12 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <algorithm>
#include <iostream>

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
	std::copy(other.ideas, other.ideas + 100, this->ideas);
	return (*this);
}

/* ************************************************************************** */
/* Member funcion */
/* ************************************************************************** */

void	Brain::addIdea(std::string idea) {
	int i = 0;
	while (!ideas[i].empty())
		i++;
	if (i < 100)
		ideas[i] = idea;
	std::cout << "Add idea nb " << i << " in brain : " << idea << std::endl;
}

void	Brain::printIdeas(void) {
	int i = 0;
	while (!ideas[i].empty())
		std::cout << ideas[i++] << std::endl;
}
