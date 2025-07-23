/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:13:40 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/23 07:38:05 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point p(0.42f, 0.042f);

	std::cout << "x = " << p.getX() << " y = " << p.getY() << std::endl;
	return (0);
}