/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:25:28 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 11:22:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
ScavTrap::ScavTrap() {
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = "";
	std::cout << GRN"ScavTrap" << RES << " default constructor"  << std::endl;
}

// Name constructor
ScavTrap::ScavTrap(std::string Name) {
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = Name;
	std::cout << GRN"ScavTrap" << RES << " constructor : " << this->_Name  << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << GRN"ScavTrap" << RES << " copy constructor called : " << this->_Name  << std::endl;
}

// Default destructor
ScavTrap::~ScavTrap() {
    std::cout << RED"ScavTrap" << RES << " destructor called : " << this->_Name  << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << "Claptrap" << RES << " copy assignement operator called : " << this->_Name<< std::endl;
	return (*this);
}


/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

// Attack member function
void	ScavTrap::attack(const std::string& target) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	this->_EnergyPoints--;
	std::cout	<< "Claptrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

// Guard gate for Scavtrap
void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_Name << " is now in GateKeeper mode" << std::endl;
}