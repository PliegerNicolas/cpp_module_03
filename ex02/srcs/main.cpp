/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:32:07 by nicolas           #+#    #+#             */
/*   Updated: 2023/08/26 14:42:15 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void	testClapTrap(void)
{

	std::cout << std::endl;
	std::cout << "\033[4;32m" << "claptrap:" << "\033[0m";
	std::cout << std::endl << std::endl;

	ClapTrap	musubi("musubi");
	ClapTrap	x;

	musubi.attack(x.getName());
	x.takeDamage(musubi.getAttackDamage());

	std::cout << std::endl;

	musubi.setAttackDamage(3);
	musubi.attack(x.getName());
	x.takeDamage(musubi.getAttackDamage());

	std::cout << std::endl;

	std::cout << "\033[37m" << "Artificially set " << x.getName();
	std::cout << "\'s ERG to 1." << "\033[0m" << std::endl;
	x.setEnergyPoints(1);
	x.beRepaired(1);
	x.beRepaired(1);

	std::cout << std::endl;

	std::cout << "\033[37m" << "Artificially set " << x.getName();
	std::cout << "\'s ERG to 5." << "\033[0m" << std::endl;
	x.setEnergyPoints(5);
	musubi.setAttackDamage(5);
	while (x.getHitPoints() > 0)
	{
		musubi.attack(x.getName());
		x.takeDamage(musubi.getAttackDamage());
	}
	musubi.attack(x.getName());
	x.takeDamage(musubi.getAttackDamage());

	std::cout << std::endl;

	x.setAttackDamage(2);
	x.attack(musubi.getName());
	musubi.takeDamage(x.getAttackDamage());
	std::cout << "\033[37m" << "Artificially set " << x.getName();
	std::cout << "\'s ERG to 5." << "\033[0m" << std::endl;
	x.setEnergyPoints(5);
	x.attack(musubi.getName());
	musubi.takeDamage(x.getAttackDamage());
	x.beRepaired(5);
}

static void	testScavTrap(void)
{

	std::cout << std::endl;
	std::cout << "\033[4;32m" << "scavtrap:" << "\033[0m";
	std::cout << std::endl << std::endl;

	ScavTrap	teyo("Teyo");
	ScavTrap	x;

	teyo.attack(x.getName());
	x.takeDamage(teyo.getAttackDamage());

	std::cout << std::endl;

	teyo.attack(x.getName());
	x.takeDamage(teyo.getAttackDamage());

	std::cout << std::endl;

	std::cout << "\033[37m" << "Artificially set " << x.getName();
	std::cout << "\'s ERG to 1." << "\033[0m" << std::endl;
	x.setEnergyPoints(1);
	x.guardGate();
	x.beRepaired(15);
	x.beRepaired(15);
	x.guardGate();
	teyo.setAttackDamage(75);
	teyo.attack(x.getName());
	x.takeDamage(teyo.getAttackDamage());
	x.guardGate();
}

static void	testFragTrap(void)
{

	std::cout << std::endl;
	std::cout << "\033[4;32m" << "fragtrap:" << "\033[0m";
	std::cout << std::endl << std::endl;

	FragTrap	shishibe("Shishibe");
	FragTrap	x;

	shishibe.attack(x.getName());
	x.takeDamage(shishibe.getAttackDamage());

	std::cout << std::endl;

	shishibe.attack(x.getName());
	x.takeDamage(shishibe.getAttackDamage());

	std::cout << std::endl;

	std::cout << "\033[37m" << "Artificially set " << x.getName();
	std::cout << "\'s ERG to 1." << "\033[0m" << std::endl;
	x.setEnergyPoints(1);
	x.highFivesGuys();
	x.beRepaired(15);
	x.beRepaired(15);
	x.highFivesGuys();
	shishibe.setAttackDamage(75);
	shishibe.attack(x.getName());
	x.takeDamage(shishibe.getAttackDamage());
	x.highFivesGuys();
}

int	main(void)
{
	testClapTrap();
	testScavTrap();
	testFragTrap();

	return (0);
}
