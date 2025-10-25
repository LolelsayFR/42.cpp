/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 12:53:11 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 13:25:44 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main( void ) {

	//Integer Array basic test
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		intArray[i] = i * 10;
	}
	std::cout << "💠 Integer Array:" << std::endl;
	for (unsigned int i = 0; i < intArray.size(); ++i) {
		std::cout << intArray[i] << std::endl;
	}

	//Out of bounds test
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "Bernard";
	std::cout << "💠 String Array:" << std::endl;
	for (unsigned int i = 0; i < strArray.size(); ++i) {
		std::cout << strArray[i] << std::endl;
	}
	try {
		std::cout << "Accessing out of bounds index:" << std::endl;
		std::cout << intArray[11] << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	//Deep copy test
	Array<std::string> copyArray = strArray;
	strArray[0] = "Goodbye";
	std::cout << "💠 Original String Array after modification:" << std::endl;
	for (unsigned int i = 0; i < strArray.size(); ++i) {
		std::cout << strArray[i] << std::endl;
	}
	std::cout << "💠 Copied String Array before modification:" << std::endl;
	for (unsigned int i = 0; i < copyArray.size(); ++i) {
		std::cout << copyArray[i] << std::endl;
	}
	return (0);
}