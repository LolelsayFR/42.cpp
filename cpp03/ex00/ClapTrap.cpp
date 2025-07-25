/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:21:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 11:22:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* All constructors and destructors */
/* ************************************************************************** */

// Default constructor
ClapTrap::ClapTrap() {
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = "";
	std::cout << GRN"Claptrap" << RES << " default constructor"  << std::endl;
}

// Name constructor
ClapTrap::ClapTrap(std::string Name) {
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = Name;
	std::cout << GRN"Claptrap" << RES << " constructor : " << this->_Name  << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << GRN"Claptrap" << RES << " copy constructor called : " << this->_Name  << std::endl;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << RED"Claptrap" << RES << " destructor called : " << this->_Name  << std::endl;
}


/* ************************************************************************** */
/* All operators overload */
/* ************************************************************************** */

// Copy operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_Name = other._Name;
    std::cout << "Claptrap" << RES << " copy assignement operator called : " << this->_Name<< std::endl;
	return (*this);
}


/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

// Attack member function
void	ClapTrap::attack(const std::string& target) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	this->_EnergyPoints--;
	std::cout	<< "Claptrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

// Take damage member function
void	ClapTrap::takeDamage(unsigned int amount) {
	this->_HitPoints -= amount;
}

// beRepaired member function
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	this->_EnergyPoints--;
	this->_HitPoints += amount;
	if (this->_HitPoints > this->_DefaultHitPoint)
		this->_HitPoints = this->_DefaultHitPoint;
}

// PrintInfo (Utils for test)
void	ClapTrap::printInfo(void) {
	std::cout	<< "\n\e[48;2;0;0;155;1m Info \e[0m" << std::endl
				<< "Name : " << this->_Name << std::endl
				<< "Hit Point : " << this->_HitPoints << std::endl
				<< "Energy point : " << this->_EnergyPoints << std::endl
				<< "Attack Damage : " << this->_AttackDamage << std::endl
				<< "\e[48;2;0;0;155;1m End of Info \e[0m\n" << std::endl;
}