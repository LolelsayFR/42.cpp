/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:23:45 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 05:15:19 by emaillet         ###   ########.fr       */
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
	return (0);
}
