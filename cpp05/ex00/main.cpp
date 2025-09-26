/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/26 19:00:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define WHI	"\e[1;38;5;0;107m "
#define RES	" \e[0m"

int	main() {
	{
	std::cout << WHI"All constructor's test" << RES << std::endl;
	Bureaucrat b1("Lowic", 151);
	Bureaucrat b2("High et fines herbes", 0);
	Bureaucrat b3("Chuck norris", 1);
	}
	{
	std::cout << WHI"All grade " << RES << std::endl;
	Bureaucrat b1("Lowic", 150);
	std::cout << b1 << std::endl;
	++b1;
	std::cout << b1 << std::endl;
	Bureaucrat b2("High et fines herbes", 1);
	std::cout << b2 << std::endl;
	--b2;
	std::cout << b2 << std::endl;
	Bureaucrat b3("Bernard", 77);
	std::cout << b3 << std::endl;
	++b3;
	std::cout << b3 << std::endl;
	--b3;
	std::cout << b3 << std::endl;
	}
	return (0);
}