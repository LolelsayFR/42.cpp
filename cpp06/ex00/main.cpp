/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:56:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/24 10:17:16 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}