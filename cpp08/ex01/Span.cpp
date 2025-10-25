/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:14:04 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 16:41:38 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
Span::Span() : N(0), list() {}

// Copy constructor
Span::Span(const Span& other) : N(other.N), list(other.list) {}

// Parameterized constructor
Span::Span(int N) : N(N), list() {}

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
	std::list<int> tmp(list);
	int minSpan = __INT_MAX__;
	tmp.sort();
	std::list<int>::iterator it = tmp.begin();
	std::list<int>::iterator end = tmp.end();
	while (it != end) {
		std::list<int>::iterator next = it;
		next++;
		if (next != end) {
			int span = *next - *it;
			if (span < minSpan)
				minSpan = span;
		}
		it++;
	}
	return (minSpan);
};

int Span::longestSpan(void) {
	if (list.size() < 2)
		throw Span::SpanCantCompareException();
	std::list<int> tmp(list);
	tmp.sort();
	return (*(--tmp.end()) - *(tmp.begin()));
};

void Span::addNumber(int number) {
	if (list.size() >= N)
		throw Span::SpanIsFullException();
	list.push_back(number);
};

void Span::addRange(int quantity) {
	srand(time(NULL));
	if (list.size() + quantity > N)
		throw Span::SpanIsFullException();
	for (int i = 0; i < quantity; i++) {
		int rval = rand();
		list.push_back(rval % __INT_MAX__);
	}
};

const char* Span::SpanIsFullException::what(void) const throw() {
	return ("🛑 Span is full, cannot add more numbers");
};

const char* Span::SpanCantCompareException::what(void) const throw() {
	return ("🛑 Not enough numbers to compare spans");
};

/* ************************************************************************** */