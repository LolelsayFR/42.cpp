/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:17:57 by emaillet          #+#    #+#             */
/*   Updated: 2026/01/31 04:53:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	RPN rpn;
	if (argc != 2) { std::cerr << ERROR_PREFIX << E_MSG_NBARG << std::endl; return (-1); }
	if (!rpn.verify(argv[1])) { std::cerr << ERROR_PREFIX << E_MSG_BAD_INPUT << std::endl; return (-1); } 
	rpn.calculate(argv[1]);
	return (0);
}
