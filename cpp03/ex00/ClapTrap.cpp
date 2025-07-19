/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:21:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/19 16:33:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_Name = "";
	std::cout << "Claptrap default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
{
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_Name = Name;
	std::cout << "Claptrap constructor : " << this->_Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Claptrap copy constructor called : " << this->_Name<< std::endl;
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_Name = other._Name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Claptrap copy assignement constructor called : " << this->_Name<< std::endl;
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_Name = other._Name;
	return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Claptrap destructor called : " << this->_Name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	std::cout	<< "ClapTrap "
				<< this->_Name
				<< " attacks "
				<< target
				<< ", causing "
				<< this->_AttackDamage
				<< " points of damage!" 
				<< std::endl;
}