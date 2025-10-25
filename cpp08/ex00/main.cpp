/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 11:58:29 by emaillet          #+#    #+#             */
/*   Updated: 2025/10/25 14:50:13 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <vector>


int main( void ) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	try {
		easyfind(vec, 9);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(vec, 3);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}