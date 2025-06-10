/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:29:54 by emaillet          #+#    #+#             */
/*   Updated: 2025/06/10 16:24:25 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	// std::cout << "Creator Weapon" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->setType(type);
	// std::cout << "Creator " << type << std::endl;
}

Weapon::~Weapon()
{
}