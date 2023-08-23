/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:33:06 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/09 13:20:59 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

/* Constructors & Destructors */

/* Public */

ClapTrap::ClapTrap(void): _name("Default")
{
	std::cout << "\033[37m" << "ClapTrap : Default constructor called";
	std::cout << "\033[0m" << std::endl;

	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;

}

ClapTrap::ClapTrap(const std::string name): _name(name)
{
	std::cout << "\033[37m" << "ClapTrap : ";
	std::cout << name << "\'s Constructor with name parameter called";
	std::cout << "\033[0m" << std::endl;

	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\033[37m" << "ClapTrap : " << _name << "\'s Destructor called";
	std::cout << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other): _name(other._name)
{
	std::cout << "\033[37m" << "ClapTrap : Copy constructor called";
	std::cout << "\033[0m" << std::endl;

	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "\033[37m" << "ClapTrap : Assignment operator called";
	std::cout << "\033[0m" << std::endl;

	if (this != &other)
	{
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;	
	}
	return (*this);
}

/* Member Functions */

/* Public */

void	ClapTrap::attack(const std::string &target)
{
	if (_energy_points <= 0)
	{
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << "\'s batteries aren't full enough to attack";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else if (_hit_points <= 0)
	{
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << " broke down. It cannot attack in this state";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;

	}
	else
	{
		_energy_points--;
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << " attacks " << target << " causing " << _attack_damage << " damage";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= 0)
	{
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << " already broke down";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
		return ;
	}

	if (amount <= 0)
	{
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << " suffers nothing";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else if (amount <= _hit_points)
	{
		_hit_points -= amount;
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << " lost some screws";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
	else
	{
		_hit_points = 0;
		_energy_points = 0;
		std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
		std::cout << " broke down";
		std::cout << "\033[0;32m" << " (HP = " << _hit_points;
		std::cout << "; ERG = " << _energy_points << ")";
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0 || _energy_points <= 0)
	{
		std::cout << "\033[1;37m";
		if (_hit_points <= 0)
		{
			std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
			std::cout << " broke down. I cannot heal itself";
			std::cout << "\033[0;32m" << " (HP = " << _hit_points;
			std::cout << "; ERG = " << _energy_points << ")";
		}
		else
		{
			std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
			std::cout << " has no energy anymore. It cannot heal itself";
			std::cout << "\033[0;32m" << " (HP = " << _hit_points;
			std::cout << "; ERG = " << _energy_points << ")";
		}
		std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
		return ;
	}

	_energy_points--;
	_hit_points += amount;
	std::cout << "\033[1;33m" << "ClapTrap : " << _name << "\033[1;37m";
	std::cout << " fixed some screws, healing itself by " << amount << " HP";
	std::cout << "\033[0;32m" << " (HP = " << _hit_points;
	std::cout << "; ERG = " << _energy_points << ")";
	std::cout << "\033[1;37m" << "." << "\033[0m" << std::endl;
}

// Getter functions

const std::string	ClapTrap::getName(void) const
{
	return (_name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (_hit_points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (_energy_points);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	if (_energy_points <= 0)
		return (0);
	return (_attack_damage);
}

// Setter functions
void	ClapTrap::setHitPoints(unsigned int points)
{
	_hit_points = points;
}

void	ClapTrap::setEnergyPoints(unsigned int points)
{
	_energy_points = points;
}

void	ClapTrap::setAttackDamage(unsigned int damage)
{
	_attack_damage = damage;
}

/* Private */
