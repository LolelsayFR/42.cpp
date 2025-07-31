/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:13:40 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/31 07:13:16 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

//Just subject main
void	subject(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

void	comparison(Fixed fi) {
	std::cout << "\nThe 6 comparison operators: >, <, >=, <=, ==, and !=. " << std::endl;
	if (fi > Fixed(0))
		std::cout << "Test > OK" << std::endl;
	if (fi < Fixed(100))
		std::cout << "Test < Ok" << std::endl;
	if (fi <= Fixed(42))
		std::cout << "Test <= Ok" << std::endl;
	if (fi >= Fixed(42))
		std::cout << "Test >= Ok" << std::endl;
	if (fi == Fixed(42))
		std::cout << "Test == Ok" << std::endl;
	if (fi != Fixed(21))
		std::cout << "Test != Ok" << std::endl;
}

void	arithmetic(Fixed fi) {
	std::cout <<  "\nThe 4 arithmetic operators: +, -, *, and /." << std::endl;
	std::cout << fi << " + 2 = " << fi + Fixed(42) << std::endl;
	std::cout << fi << " - 2 = " << fi - Fixed(42) << std::endl;
	std::cout << fi << " / 2 = " << fi / Fixed(2) << std::endl;
	std::cout << fi << " * 2 = " << fi * Fixed(2) << std::endl;
	std::cout << fi << " + -42 = " << fi + Fixed(-42) << std::endl;
	std::cout << fi << " - -42 = " << fi - Fixed(-42) << std::endl;
	std::cout << fi << " * -42 = " << fi * Fixed(-42) << std::endl;
	std::cout << fi << " / -42 = " << fi / Fixed(-42) << std::endl;
}

void	incr_and_decr(Fixed fi) {
	std::cout <<  "\nThe 4 increment/decrement operators, (fi++ fi-- ++fi --fi)" << std::endl;
	std::cout << "The fi value is : " << fi << std::endl;
	std::cout << "fi++ action : " << fi++ << std::endl;
	std::cout << "The fi value is : " << fi << std::endl;
	std::cout << "fi-- action : " << fi-- << std::endl;
	std::cout << "The fi value is : " << fi << std::endl;
	std::cout << "++fi action : " << ++fi << std::endl;
	std::cout << "The fi value is : " << fi << std::endl;
	std::cout << "--fi action : " << --fi << std::endl;
	std::cout << "The fi value is : " << fi << std::endl;
}

// All operator test
void	other(void) {
	Fixed fi(42);
	std::cout << "\nI declare a fixed object, fi value is : " << fi << std::endl;

	comparison(fi);
	arithmetic(fi);
	incr_and_decr(fi);

	Fixed a(0.42f);
	Fixed b(0.042f);
	const Fixed &ca = a;
	const Fixed &cb = b;

	std::cout << "\nThe 4 member function (min, max etc) " << std::endl;
	std::cout << "Max const return : " << Fixed::max(ca, cb) << std::endl;
	std::cout << "Max return : " << Fixed::max(a, b) << std::endl;
	std::cout << "Min const return : " << Fixed::min(ca, cb) << std::endl;
	std::cout << "Min return : " << Fixed::min(a, b) << std::endl;
}


int main( void ) {
	std::cout << "\n\e[48;2;0;0;155;1m Subject test \e[0m\n" << std::endl;
	subject();
	std::cout << "\n\e[48;2;0;0;155;1m My test \e[0m" << std::endl;
	other();
	std::cout << "\n\e[48;2;0;0;155;1m End \e[0m\n" << std::endl;
	return (0);
}