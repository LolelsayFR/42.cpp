/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:25:28 by emaillet          #+#    #+#             */
/*   Updated: 2025/07/25 11:19:42 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

/* ************************************************************************** */
/* All constructors and the destructor */
/* ************************************************************************** */

// Default constructor
FragTrap::FragTrap() {
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = "";
	std::cout << GRN"FragTrap" << RES << " default constructor"  << std::endl;
}

// Name constructor
FragTrap::FragTrap(std::string Name) {
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	this->_DefaultHitPoint = this->_HitPoints;
	this->_Name = Name;
	std::cout << GRN"FragTrap" << RES << " constructor : " << this->_Name  << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << GRN"FragTrap" << RES << " copy constructor called : " << this->_Name  <<std::endl;
}

// Default destructor
FragTrap::~FragTrap() {
    std::cout << RED"FragTrap" << RES << " destructor called : " << this->_Name  << std::endl;
}


/* ************************************************************************** */
/* All operator overload */
/* ************************************************************************** */

// Copy Operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
	this->_HitPoints = other._HitPoints;
	this->_EnergyPoints = other._EnergyPoints;
	this->_AttackDamage = other._AttackDamage;
	this->_DefaultHitPoint = other._HitPoints;
	this->_Name = other._Name;
    std::cout << "FragTrap" << RES << " copy assignement operator called : " << this->_Name<< std::endl;
	return (*this);
}


/* ************************************************************************** */
/* All other member functions */
/* ************************************************************************** */

// Attack member function
void	FragTrap::attack(const std::string& target) {
	if (this->_EnergyPoints <= 0 || this->_HitPoints <= 0)
		return ;
	this->_EnergyPoints--;
	std::cout	<< "FragTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
}

// Guard gate for FragTrap
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_Name << " need a mate to make a Hight five !" << std::endl;
}