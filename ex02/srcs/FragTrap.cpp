/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:19 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/09 13:25:32 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "FragTrap.hpp"

/* Constructors & Destructors */

/* Public */

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "\033[37m" << "FragTrap : ";
	std::cout << "Default constructor called" << "\033[0m" << std::endl;

	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	std::cout << "\033[37m" << "FragTrap : ";
	std::cout << name << "\'s Constructor with name parameter called";
	std::cout << "\033[0m" << std::endl;

	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::~FragTrap(void)
{
	std::cout << "\033[37m" << "FragTrap : " << getName() << "\'s Destructor called";
	std::cout << "\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	std::cout << "\033[37m" << "FragTrap : Copy constructor called";
	std::cout << "\033[0m" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "\033[37m" << "FragTrap : Assignment operator called";
	std::cout << "\033[0m" << std::endl;

	if (this != &other)
		ClapTrap::operator=(other);
	return (*this);
}

/* Member Functions */

/* Public */

void	FragTrap::attack(const std::string &target)
{
	if (getEnergyPoints() <= 0)
	{
		std::cout << "\033[1;33m" << "FragTrap : " << getName() << "\033[1;37m";
		std::cout << "\'s batteries aren't full enough to attack";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "\033[1;33m" << "FragTrap : " << getName() << "\033[1;37m";
		std::cout << " attacks " << target << " causing " << getAttackDamage() << " damage";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	if (getHitPoints() <= 0)
	{
		std::cout << "\033[1;33m" << "FragTrap : " << getName() << "\033[1;37m";
		std::cout << " broke down. He can't handle to lift his arm to High Five";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else
	{
		std::cout << "\033[1;33m" << "FragTrap : " << getName() << "\033[1;37m";
		std::cout << " wants to high five !";
		std::cout << "\033[0;32m" << " (HP = " << getHitPoints();
		std::cout << "; ERG = " << getEnergyPoints() << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

/* Private */
