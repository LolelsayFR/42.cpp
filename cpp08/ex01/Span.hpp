/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:17:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/12/13 21:24:29 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <list>
#include <iterator>
#include <exception>

class Span
{
private:
	const unsigned int N;
	std::list<int> list;
public:
	// Constructor: only parameter is the maximum capacity
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	int shortestSpan(void);
	int longestSpan(void);

	// Optional: addRange by quantity (kept in .cpp)
	void addRange(int quantity);

	class SpanIsFullException : public std::exception {
	public :
		virtual const char* what(void) const throw();
	};
	class SpanCantCompareException : public std::exception {
	public :
		virtual const char* what(void) const throw();
	};

};