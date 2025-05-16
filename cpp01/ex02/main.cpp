/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:01:55 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/16 12:24:05 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string		&stringREF = str;
	std::string		*stringPTR = &str;

	std::cout << "str Address : "<< &str << std::endl;
	std::cout << "PTR Address : "<< stringPTR << std::endl;
	std::cout << "REF Address : "<< &stringREF << std::endl;
	
	std::cout << "str Content : "<< str << std::endl;
	std::cout << "PTR Content : "<< *stringPTR << std::endl;
	std::cout << "REF Content : "<< stringREF << std::endl;
}
