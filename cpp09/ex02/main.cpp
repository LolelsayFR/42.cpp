/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:46:24 by emaillet          #+#    #+#             */
/*   Updated: 2026/02/02 10:17:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Utils test ./PmergeMe $(shuf -i 1-30000 -n 3000 | tr '\n' ' ')

int main(int argc, char *argv[])
{
	if (argc == 1 || argc > 3001) { std::cerr << ERROR_PREFIX << E_MSG_NBARG << std::endl; return (-1); }
	try {
		PmergeMe pmergeme(argv);
		pmergeme.vecSort();
		pmergeme.dequeSort();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
