/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:04 by emaillet          #+#    #+#             */
/*   Updated: 2025/12/13 21:45:04 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <algorithm>
#include <vector>
#include <functional> // for std::minus
#include <limits>     // for std::numeric_limits
#include <numeric>     // for std::adjacent_difference
#include <cstdlib>     // for rand
#include <climits>     // for INT_MAX
#include <iterator>    // for back_inserter
#include <iostream>

// C++98-compatible random generator function for generate_n
static int RandGen_func()
{
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		seeded = true;
	}
	return std::rand() % INT_MAX;
}

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Span::Span() : N(0), list() {}

// Copy constructor
Span::Span(const Span& other) : N(other.N), list(other.list) {}

// Parameterized constructor (only constructor that sets capacity)
Span::Span(unsigned int N) : N(N), list() {}

// Default destructor
Span::~Span() {
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
Span& Span::operator=(const Span& other) {
	list = other.list;
	return (*this);
}


/* ************************************************************************** */
/* All other function and exceptions */
/* ************************************************************************** */

int Span::shortestSpan(void) {
	if (list.size() < 2)
		throw Span::SpanCantCompareException();
	std::vector<int> tmp(list.begin(), list.end());
	std::sort(tmp.begin(), tmp.end());
	std::vector<int> diffs(tmp.size());
	std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin(), std::minus<int>());
	std::vector<int>::iterator minIt = std::min_element(diffs.begin() + 1, diffs.end()); //Ignore the first element (not a difference)
	return *minIt;
}

int Span::longestSpan(void) {
	if (list.size() < 2)
		throw SpanCantCompareException();
    int minVal = *std::min_element(list.begin(), list.end());
    int maxVal = *std::max_element(list.begin(), list.end());
    return maxVal - minVal;
}

void Span::addNumber(int number) {
	if (list.size() >= N)
		throw Span::SpanIsFullException();
	list.push_back(number);
};

void Span::addRange(int quantity) {
	if (list.size() + quantity > N)
		throw Span::SpanIsFullException();
	std::generate_n(std::back_inserter(list), quantity, RandGen_func);
}

const char* Span::SpanIsFullException::what(void) const throw() {
	return ("🛑 Span is full, cannot add more numbers");
};

const char* Span::SpanCantCompareException::what(void) const throw() {
	return ("🛑 Not enough numbers to compare spans");
};

/* ************************************************************************** */