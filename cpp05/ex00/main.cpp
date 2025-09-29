/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/29 11:25:44 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define WHI	"\e[1;38;5;0;107m "
#define RES	" \e[0m"

int	main() {
	{// First part
	std::cout << WHI"All constructor's test" << RES << std::endl;
	try {
		Bureaucrat b1("Lowic", 151);
	}
	catch (std::exception& e) {
		std::cout << "Constructor low grade : " << e.what() << std::endl;
	}
	try {
		Bureaucrat b2("High et fines herbes", 0);
	}
	catch (std::exception& e) {
		std::cout << "Constructor high grade : " << e.what() << std::endl;
	}
	Bureaucrat b3("Chuck norris", 1);
	}//End of first part
	{//Second part
	std::cout << WHI"All grade " << RES << std::endl;
	try {
		Bureaucrat b1("Lowic", 150);
		Bureaucrat b2("High et fines herbes", 1);
		Bureaucrat b3("Bernard", 77);
		std::cout << b1 << std::endl;
		try {
			--b1;
		}
		catch (std::exception& e) {
			std::cout << "Decrement : " << e.what() << std::endl;
		}
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		try {
			++b2;
		}
		catch (std::exception& e) {
			std::cout << "Increment : " << e.what() << std::endl;
		}
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		++b3;
		std::cout << b3 << std::endl;
		--b3;
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Constructor low grade : " << e.what() << std::endl;
	}
	} // end of second part
	return (0);
}