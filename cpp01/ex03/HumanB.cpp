/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:39 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/15 09:45:18 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB()
{
	this->weapon = NULL;
}

HumanB::HumanB(std::string Name)
{
	this->weapon = NULL;
	this->setName(Name);
	// std::cout << "Creator B " << Name << " take " << this->weapon.getType() << std::endl;
}

HumanB::~HumanB()
{
}
void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->Name << " attacks without weapon."<< std::endl;
	else
		std::cout << this->Name << " attacks with their " << this->weapon->getType() << std::endl;
}