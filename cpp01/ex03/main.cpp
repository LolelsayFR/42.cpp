/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/10 17:46:03 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		club.setType("some error props mdl");
		club.setType("the gordon's crowbar");
		bob.attack();
	}
	{
		Weapon watermelon = Weapon("Huge watermelon");
		HumanB jim("Jim");
		jim.setWeapon(watermelon);
		jim.attack();
		watermelon.setType("Half of watermelon");
		jim.attack();
	}
return 0;
}
