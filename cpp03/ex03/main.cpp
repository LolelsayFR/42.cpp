/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:23:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/06 08:00:40 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("Jostophe");

	a.printInfo();
	a.whoAmI();
	a.printInfo();
	a.highFivesGuys();
	a.printInfo();
	a.guardGate();
	a.printInfo();
	a.attack("Joel and Christophe");
	a.printInfo();
	return (0);
}
