/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:23 by emaillet          #+#    #+#             */
/*   Updated: 2025/12/13 21:21:35 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main( void ) {
	{
		std::cout << "💠 Basic test" << std::endl;	
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n💠 Exception test (Span is full)" << std::endl;
		// create a span with capacity 0 to test "full" behavior
		Span sp = Span(0);
		try {
			sp.addNumber(6);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n💠 Exception test (Can't compare)" << std::endl;
		Span sp = Span(3);
		try {
			sp.addNumber(6);
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n💠 Large Span test" << std::endl;
		Span sp = Span(10000);
		try {
			sp.addRange(10000);
			std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
			std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}