/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/29 08:57:28 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define WHI	"\e[1;38;5;0;107m "
#define RES	" \e[0m"

void tryform(std::string name, int gts, int gte) {
	try {
		Form(name, gts, gte);	
	}
	catch (std::exception& e) {
		std::cout << name << " Form Constructor : " << e.what() << std::endl;
	}
}

int	main() {
	{
		std::cout << WHI"All form constructor's test" << RES << std::endl;
		tryform("f0", 1, 1);
		tryform("f1", 151, 150);
		tryform("f2", 150, 151);
		tryform("f3", 1, 0);
		tryform("f4", 0, 1);
	}
	{
		std::cout << WHI"All other test" << RES << std::endl;
		Form f1("f1", 100, 100);
		Form f1c(f1);
		Bureaucrat b1("Bernard", 99);
		std::cout << b1 << std::endl << f1 << std::endl;
		try {
			b1.signForm(f1);
		}
		catch (std::exception& e) {
			std::cout << "Form Constructor : " << e.what() << std::endl;
		}
		std::cout << f1 << std::endl;
		--b1, --b1;
		std::cout << b1 << std::endl << f1c << std::endl;
		try  {
			b1.signForm(f1c);
		}
		catch (std::exception& e) {
			std::cout << "Form Constructor : " << e.what() << std::endl;
		}
		std::cout << f1c << std::endl;
	}
	return (0);
}