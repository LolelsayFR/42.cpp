/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:46:24 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/31 07:20:25 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 4000) { std::cerr << ERROR_PREFIX << E_MSG_NBARG << std::endl; return (-1); }
	try {
		PmergeMe pmergeme(argv);
		//pmergeme.sort();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
