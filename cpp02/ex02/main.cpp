/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:13:40 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 03:53:22 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << Fixed(7) * Fixed(5) << std::endl;
	std::cout << Fixed(35) / Fixed(5) << std::endl;
	std::cout << Fixed::min(Fixed(42), Fixed(0.42f)) << std::endl;

	if (a < b)
		std::cout << "a < c" << std::endl;
	return (0);
}