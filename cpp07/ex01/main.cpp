/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:23 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/29 09:41:50 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void print(std::string const& str) {
	std::cout << "String: " << str << std::endl;
}

void print(int const& i) {
	std::cout << "Integer: " << i << std::endl;
}

int main( void ) {
	int intArray[] = {0, 1, 2, 3, 4};
	std::cout << "💠 Integer array:" << std::endl;
	iter<int>(intArray, 5, print); //explicit template instantiation

	std::cout << std::endl;

	std::string strArray[] = {"Hello", "World", "Bernard", "Chuck", "Norris"};
	std::cout << "💠 String array:" << std::endl;
	iter(strArray, 5, print); //implicit template instantiation

	return 0;
}