/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:33:37 by emaillet          #+#    #+#             */
/*   Updated: 2026/02/01 18:37:32 by emaillet         ###   ########.fr       */
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

/* ************************************************************************** */
/* Ford Jhonson utils fonctions */
/* ************************************************************************** */

std::vector<size_t> getJacobsthalList(size_t size) {
	std::vector<size_t> result;
	result.push_back(0);
	if (size == 0) 
		return (result);
	result.push_back(1);	
	if (size == 1)
		return (result);
	for (size_t i = 2; i <= size; i++) {
		result.push_back(result[i - 1] + 2 * result[i - 2]);
	}
	return (result);
}

void printCon(std::vector<unsigned int> con) {
	for (	std::vector<unsigned int>::iterator it = con.begin(); it != con.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printCon(std::deque<unsigned int> con) {
	for (	std::deque<unsigned int>::iterator it = con.begin(); it != con.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void mergeCon(std::vector<unsigned int>& container, std::vector<unsigned int>& other) {
    std::vector<size_t> jacobIndices = getJacobsthalList(other.size());
    std::vector<size_t> order;
	if (!other.empty())
		order.push_back(0);
	for (size_t i = 0; i < jacobIndices.size() - 1; ++i) {
		size_t current = jacobIndices[i + 1];
		size_t prev = jacobIndices[i];
		if (current >= other.size())
			current = other.size() - 1;
		while (current > prev) {
			order.push_back(current);
			current--;
		}
	}
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); ++it) {
		std::vector<unsigned int>::iterator pos = std::lower_bound(container.begin(), container.end(), other[*it]);
		container.insert(pos, other[*it]);
	}
}

void mergeCon(std::deque<unsigned int>& container, std::deque<unsigned int>& other) {
	std::vector<size_t> jacobIndices = getJacobsthalList(other.size());
	std::vector<size_t> order;
	if (!other.empty())
		order.push_back(0);
	for (size_t i = 0; i < jacobIndices.size() - 1; ++i) {
		size_t current = jacobIndices[i + 1];
		size_t prev = jacobIndices[i];
		if (current >= other.size())
			current = other.size() - 1;
		while (current > prev) {
			order.push_back(current);
			current--;
		}
	}
	for (std::vector<size_t>::iterator it = order.begin(); it != order.end(); ++it) {
		std::deque<unsigned int>::iterator pos = std::lower_bound(container.begin(), container.end(), other[*it]);
		container.insert(pos, other[*it]);
	}
}

void sortCon(std::vector<unsigned int>& container) {
	int i = 0;
	if (container.size() <= 1)
		return ;
	std::vector<unsigned int> main; 
	std::vector<unsigned int> pending; 
	std::vector<unsigned int>::iterator oldIt = container.begin();
	for (std::vector<unsigned int>::iterator it = container.begin(); it != container.end(); i++, it++) {
		if (i % 2 == 0){
			oldIt = it;
			continue;
		}
		main.push_back(*oldIt > *it ? *oldIt : *it);
		pending.push_back(*oldIt < *it ? *oldIt : *it);
	}
	if (container.size() % 2 == 1 && container.size() > 0)
		pending.push_back(container.back());
	sortCon(main);
	mergeCon(main, pending);
	container = main;
}

void sortCon(std::deque<unsigned int>& container) {
	int i = 0;
	if (container.size() <= 1)
		return ;
	std::deque<unsigned int> main; 
	std::deque<unsigned int> pending; 
	std::deque<unsigned int>::iterator oldIt = container.begin();
	for (std::deque<unsigned int>::iterator it = container.begin(); it != container.end(); i++, it++) {
		if (i % 2 == 0){
			oldIt = it;
			continue;
		}
		main.push_back(*oldIt > *it ? *oldIt : *it);
		pending.push_back(*oldIt < *it ? *oldIt : *it);
	}
	if (container.size() % 2 == 1 && container.size() > 0)
		pending.push_back(container.back());
	sortCon(main);
	mergeCon(main, pending);
	container = main;
}

/* ************************************************************************** */
/* Ford Jhonson sort fonctions */
/* ************************************************************************** */

std::string PmergeMe::vecSort(void) {
	std::string result;
	sortCon(this->vector);
	printCon(this->vector);

	return (result);
}

std::string PmergeMe::dequeSort(void) {
	std::string result;
	sortCon(this->deque);
	printCon(this->deque);

	return (result);
}