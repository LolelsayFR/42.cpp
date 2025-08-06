/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:21:51 by emaillet          #+#    #+#             */
/*   Updated: 2025/08/06 08:03:30 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/* All constructors and destructors */
/* ************************************************************************** */

// Default constructor
DiamondTrap::DiamondTrap() {
	this->_Name = "";
	this->_EnergyPoints = ScavTrap("getEnergyPoint").getEnergyPoint();
	std::cout << GRN"DiamondTrap" << RES << " default constructor" << std::endl;
}

// Name constructor
DiamondTrap::DiamondTrap(std::string Name) {
	this->_Name = Name;
	this->_EnergyPoints = ScavTrap("getEnergyPoint").getEnergyPoint();
	ClapTrap::_Name = Name + "_clap_name";
	this->_DefaultHitPoint = this->_HitPoints;
	std::cout << GRN"DiamondTrap" << RES << " constructor : " << this->_Name << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << GRN"DiamondTrap" << RES << " copy constructor called : " << this->_Name<< std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << RED"DiamondTrap" << RES << " destructor called : " << this->_Name << std::endl;
}


/* ************************************************************************** */
/* All operators overload */
/* ************************************************************************** */

// Copy operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << "DiamondTrap copy assignement operator called : " << this->_Name<< std::endl;
	return (*this);
}


/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

// Who am i
void DiamondTrap::whoAmI(void) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	this->_EnergyPoints--;
	std::cout << "DiamondTrap name is " << this->_Name << " and ClapTrap name is " << ClapTrap::_Name << std::endl;
}
