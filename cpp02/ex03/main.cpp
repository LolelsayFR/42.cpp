/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:13:40 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/02 03:08:26 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) {
	std::cout << "\n\e[48;2;0;0;155;1m My test \e[0m\n" << std::endl;

	const Point	a(0, 0);
	const Point	b(1, 0);
	const Point	c(0, 1);
	const Point	p(0.5f, 0.49f);

	std::cout << "'a' point : x = " << a.getX() << " y = " << a.getY() << std::endl;
	std::cout << "'b' point : x = " << b.getX() << " y = " << b.getY() << std::endl;
	std::cout << "'c' point : x = " << c.getX() << " y = " << c.getY() << std::endl;
	std::cout << "'p' point : x = " << p.getX() << " y = " << p.getY() << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "\nThe point 'p' \e[48;2;0;100;0;1m IS \e[0m in the triangle 'abc'" << std::endl;
	else
		std::cout << "\nThe point 'p' \e[48;2;100;0;0;1m IS NOT \e[0m in the triangle 'abc'" << std::endl;
	
	std::cout << "\n\e[48;2;0;0;155;1m End \e[0m\n" << std::endl;
	return (0);
}