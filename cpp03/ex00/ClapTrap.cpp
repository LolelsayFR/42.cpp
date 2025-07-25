/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:21:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 05:16:29 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* All constructors and destructors */
/* ************************************************************************** */

ClapTrap::ClapTrap() {
	std::cout << "Claptrap default constructor" << std::endl;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = "";
}

ClapTrap::ClapTrap(std::string Name) {
	std::cout << "Claptrap constructor : " << this->_Name << std::endl;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = Name;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Claptrap copy constructor called : " << this->_Name<< std::endl;
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
}

ClapTrap::~ClapTrap() {
    std::cout << "Claptrap destructor called : " << this->_Name << std::endl;
}


/* ************************************************************************** */
/* All operators overload */
/* ************************************************************************** */

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Claptrap copy assignement constructor called : " << this->_Name<< std::endl;
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_Name = other._Name;
	return (*this);
}


/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

void	ClapTrap::attack(const std::string& target) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	std::cout	<< "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	this->_EnergyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	this->_EnergyPoints--;
	this->_HitPoints += amount;
	if (this->_HitPoints > this->_DefaultHitPoint)
		this->_HitPoints = this->_DefaultHitPoint;
}

void	ClapTrap::printInfo(void) {
	std::cout	<< "\n\e[48;2;0;0;155;1m ClapTrap Info \e[0m" << std::endl
				<< "Name : " << this->_Name << std::endl
				<< "Actual Hit Point : " << this->_HitPoints << std::endl
				<< "Default Hit point : " << this->_DefaultHitPoint << std::endl
				<< "Energy point : " << this->_EnergyPoints << std::endl
				<< "Attack Damage : " << this->_AttackDamage << std::endl
				<< "\e[48;2;0;0;155;1m End of Info \e[0m\n" << std::endl;
}