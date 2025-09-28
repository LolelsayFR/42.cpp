/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolelsay <lolelsay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 09:13:52 by emaillet          #+#    #+#             */
/*   Updated: 2025/09/28 11:54:12 by lolelsay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define WHI	"\e[1;38;5;0;107m "
#define RES	" \e[0m"

int	main() {
	{
		std::cout << WHI"All form constructor's test" << RES << std::endl;
		Form f0("f0", 1, 1);
		Form f1("f1", 151, 150);
		Form f2("f2", 150, 151);
		Form f3("f3", 1, 0);
		Form f4("f4", 0, 1);
		Form f0c(f0);
		std::cout << f0 << f0c << std::endl;
	}
	{
		std::cout << WHI"All other test" << RES << std::endl;
		Form f1("f1", 100, 100);
		Form f1c(f1);
		Bureaucrat b1("Bernard", 99);
		std::cout << b1 << std::endl << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		++b1, ++b1;
		std::cout << b1 << std::endl << f1c << std::endl;
		b1.signForm(f1c);
		std::cout << f1c << std::endl;
	}
	return (0);
}