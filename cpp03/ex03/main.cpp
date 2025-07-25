/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:23:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 10:46:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("Jostophe");

	a.whoAmI();
	a.highFivesGuys();
	a.guardGate();
	a.printInfo();
	a.attack("Joel and Christophe");
	a.printInfo();
	return (0);
}