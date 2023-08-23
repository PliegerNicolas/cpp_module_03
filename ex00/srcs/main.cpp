/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:32:07 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/09 13:35:45 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"

static void	testClapTrap(void)
{

	std::cout << std::endl;
	std::cout << "\033[4;32m" << "claptrap:" << "\033[0m";
	std::cout << std::endl << std::endl;

	ClapTrap	musubi("Musubi");
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

int	main(void)
{
	testClapTrap();

	return (0);
}
