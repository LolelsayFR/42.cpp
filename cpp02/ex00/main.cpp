/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:13:40 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/31 07:22:33 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int subject( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    a.setRawBits(0);
    return (0);
}

int main( void ) {

	std::cout << "\n\e[48;2;0;0;155;1m Subject test \e[0m\n" << std::endl;
	subject();
	std::cout << "\n\e[48;2;0;0;155;1m End \e[0m\n" << std::endl;
	return (0);
}