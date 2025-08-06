/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:23:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/06 07:11:32 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Arnaud");
	ClapTrap	b("Bernard");

	b.printInfo();
	b.attack("Arnaud");
	b.printInfo();
    std::cout << "takeDamage Function (-5 hit points)" << std::endl;
    b.takeDamage(5);
    b.printInfo();
    std::cout << "beRepaired Function (+4 Hit points)" << std::endl;
    b.beRepaired(4);
    b.printInfo();
	return (0);
}
