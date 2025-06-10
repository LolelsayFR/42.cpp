/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:39 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/10 17:06:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB()
{
	this->weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->setName(name);
	// std::cout << "Creator B " << name << " take " << this->weapon.getType() << std::endl;
}

HumanB::~HumanB()
{
}
void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " attacks without weapon."<< std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}