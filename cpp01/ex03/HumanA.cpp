/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:28:55 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/10 17:09:52 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA()
{
	this->weapon[0] = Weapon("Placeholder weapon");
	// std::cout << "Creator A" << " take " << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	this->setName(name);
	this->setWeapon(weapon);
	// std::cout << "Creator A " << name << " take " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}