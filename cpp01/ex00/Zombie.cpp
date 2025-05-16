/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:01:41 by emaillet          #+#    #+#             */
/*   Updated: 2025/05/16 10:35:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << this->name << " is destruct." << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << " : BraiiiiiiinnnzzzZ.." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}