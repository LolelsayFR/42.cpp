/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:33:37 by emaillet          #+#    #+#             */
/*   Updated: 2026/02/05 12:53:59 by emaillet         ###   ########.fr       */
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
/* Ford Jhonson utils fonctions template */
/* ************************************************************************** */

//Jacobsthal list generator
template <typename T>
T getJacobsthalList(size_t size) {
	T result;
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


//Ford jhonson merge insertion function
template <typename T>
void mergeCon(T& container, T& other) {
	T jacobIndices = getJacobsthalList<T>(other.size());
	T order;
	if (!other.empty())
		order.push_back(0);
	for (size_t i = 0; i < jacobIndices.size() - 1; ++i) {
		size_t current = jacobIndices[i + 1];
		size_t prev = jacobIndices[i];
		if (current >= other.size())
			current = other.size() - 1;
		while (current > prev) {
			if (current != 0)
				order.push_back(current);
			current--;
		}
	}
	for (typename T::iterator it = order.begin(); it != order.end(); ++it) {
		typename T::iterator pos = std::lower_bound(container.begin(), container.end(), other[*it]);
		container.insert(pos, other[*it]);
	}
}

//Recusrive sort function
template <typename T>
clock_t sortCon(T& container) {
	clock_t t = clock();
	int i = 0;
	if (container.size() <= 1)
		return (clock() - t);
	T main; 
	T pending; 
	typename T::iterator oldIt = container.begin();
	for (typename T::iterator it = container.begin(); it != container.end(); i++, it++) {
		if (i % 2 == 0){
			oldIt = it;
			continue;
		}
		main.push_back(*oldIt > *it ? *oldIt : *it);
		pending.push_back(*oldIt < *it ? *oldIt : *it);
	}
	if (container.size() % 2 == 1 && !container.empty())
		pending.push_back(container.back());
	sortCon<T>(main);
	mergeCon<T>(main, pending);
	container = main;
	return (clock() - t);
}

/* ************************************************************************** */
/* Other utils function template  */
/* ************************************************************************** */

//Print utils
template <typename T>
void printCon(T& con) {
	for (typename T::iterator it = con.begin(); it != con.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/* Sort and messages iteration */
/* ************************************************************************** */

//Vec sort iteration
void PmergeMe::vecSort(void) {
	
	std::cout << "\e[1;34mBefore:\t";
	printCon<std::vector<unsigned int> >(this->vector);
	clock_t t = sortCon<std::vector<unsigned int> >(this->vector);
	std::cout << "\e[1;32mAfter:\t";
	printCon<std::vector<unsigned int> >(this->vector);
	std::cout	<< "\e[1;35mTime to process a range of "
				<< this->vector.size()
				<< std::setw(4)
				<< " elements with std::vector<unsigned int>\t: "
				<< std::fixed 
				<< std::setprecision(6)
				<< ((float)t) / CLOCKS_PER_SEC 
				<< " us"
				<< std::endl;
}

//Deque sort iteration
void PmergeMe::dequeSort(void) {
	clock_t t = sortCon<std::deque<unsigned int> >(this->deque);

	std::cout	<< "\e[1;31mTime to process a range of "
				<< this->deque.size()
				<< std::setw(4)
				<< " elements with std::deque<unsigned int>\t: "
				<< std::fixed 
				<< std::setprecision(6)
				<< ((float)t) / CLOCKS_PER_SEC 
				<< " us\e[0m"
				<< std::endl;
}

/* ************************************************************************** */
/* End of file */
/* ************************************************************************** */