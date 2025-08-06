/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:23:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/06 07:58:56 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("Serena");
	a.printInfo();
	a.attack("Jostophe");
	a.printInfo();
	a.guardGate();
    a.printInfo();
    std::cout << "takeDamage Function (-5 hit points)" << std::endl;
    a.takeDamage(5);
    a.printInfo();
    std::cout << "beRepaired Function (+4 Hit points)" << std::endl;
    a.beRepaired(4);
    a.printInfo();
	return (0);
}
