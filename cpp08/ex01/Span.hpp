/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:17:44 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 16:11:05 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <list>


class Span
{
private:
	const size_t N;
	std::list<int> list;
public:
	Span(void);
	Span(int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();
	void addNumber(int number);
	int shortestSpan(void);
	int longestSpan(void);
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