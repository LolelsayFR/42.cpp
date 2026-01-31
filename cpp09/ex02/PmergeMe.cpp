/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:33:37 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/31 07:20:05 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* Exception */
/* ************************************************************************** */

errorException::errorException(std::string msg) throw(): msg(ERROR_PREFIX + msg) {};
const char* errorException::what(void) const throw() { return (this->msg.c_str()); };
errorException::~errorException() throw() {};

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
PmergeMe::PmergeMe() {
}

//Assignation constructor
PmergeMe::PmergeMe(char** argv) {
	char* stash;
	long value;

	for (int i = 1; argv[i] != NULL; i++) {
		value = strtol(argv[i], &stash, 10);
		if (value > INT_MAX || value < 0 || !std::string(stash).empty())
			throw (errorException(E_MSG_BAD_INPUT));
		this->deque.push_back(value);
		this->vector.push_back(value);
	}
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : deque(other.deque), vector(other.vector) {
}

// Default destructor
PmergeMe::~PmergeMe() {
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	this->deque = other.deque;
	this->vector = other.vector;
	return (*this);
}