/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:19 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/09 13:18:55 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"

/* Constructors & Destructors */

/* Public */

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "\033[37m" << "ScavTrap : ";
	std::cout << "Default constructor called" << "\033[0m" << std::endl;

	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	_guarding_gate = false;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	std::cout << "\033[37m" << "ScavTrap : ";
	std::cout << name << "\'s Constructor with name parameter called";
	std::cout << "\033[0m" << std::endl;

	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	_guarding_gate = false;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\033[37m" << "ScavTrap : " << getName() << "\'s Destructor called";
	std::cout << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	std::cout << "\033[37m" << "ScavTrap : Copy constructor called";
	std::cout << "\033[0m" << std::endl;

	_guarding_gate = other._guarding_gate;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "\033[37m" << "ScavTrap : Assignment operator called";
	std::cout << "\033[0m" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		_guarding_gate = other._guarding_gate;
	}
	return (*this);
}

/* Member Functions */

/* Public */

void	ScavTrap::attack(const std::string &target)
{
	if (getEnergyPoints() <= 0)
	{
		std::cout << "\033[1;33m" << "ScavTrap : " << getName() << "\033[1;37m";
		std::cout << "\'s batteries aren't full enough to attack";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "\033[1;33m" << "ScavTrap : " << getName() << "\033[1;37m";
		std::cout << " attacks " << target << " causing " << getAttackDamage() << " damage";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "\033[1;33m" << "ScavTrap : " << getName() << "\033[1;37m";
		std::cout << " broke down. It isn't very succesful in guarding the gate";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else if (_guarding_gate)
	{
		std::cout << "\033[1;33m" << "ScavTrap : " << getName() << "\033[1;37m";
		std::cout << " is already guarding the gate";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else
	{
		_guarding_gate = true;
		std::cout << "\033[1;33m" << "ScavTrap : " << getName() << "\033[1;37m";
		std::cout << " starts guarding the gate";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

/* Private */
