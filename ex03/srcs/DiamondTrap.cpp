/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:03:47 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/09 14:04:59 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DiamondTrap.hpp"

/* Constructors & Destructors */

/* Public */

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap(),
								_name(getName() + "_clap_name")
{
	std::cout << "\033[37m" << "DiamondTrap : ";
	std::cout << "Default constructor called" << "\033[0m" << std::endl;

	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name),
												ScavTrap(name), FragTrap(name),
												_name(getName() + "_clap_name")
{
	std::cout << "\033[37m" << "DiamondTrap : ";
	std::cout << name << "\'s Constructor with name parameter called";
	std::cout << "\033[0m" << std::endl;

	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "\033[37m" << "DiamondTrap : " << getName() << "\'s Destructor called";
	std::cout << "\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other),
													FragTrap(other), _name(other._name)
{
	std::cout << "\033[37m" << "DiamondTrap : Copy constructor called";
	std::cout << "\033[0m" << std::endl;

	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "\033[37m" << "DiamondTrap : Assignment operator called";
	std::cout << "\033[0m" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}


/* Member Functions */

/* Public */

void	DiamondTrap::whoAmI(void)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "\033[1;33m" << "DiamondTrap : " << _name << "\033[1;37m";
		std::cout << " broke down. It cannot give it's names";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else if (getEnergyPoints() <= 0)
	{
		std::cout << "\033[1;33m" << "DiamondTrap : " << _name << "\033[1;37m";
		std::cout << " hasn't got enough energy to give it's names";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1;33m" << "DiamondTrap : " << _name << "\033[1;37m";
		std::cout << "\'s my name and my ClapTrap's name is " << getName();
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

/* Private */
