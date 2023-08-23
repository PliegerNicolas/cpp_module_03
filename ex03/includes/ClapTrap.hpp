/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 18:33:20 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/08 12:40:49 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	public:
		/* Attributes */

		/* Constructors & Destructors */
		ClapTrap(void);
		ClapTrap(const std::string name);

		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);

		~ClapTrap(void);

		/* Member functions */

		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		// Getter functions

		const std::string	getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttackDamage(void) const;

		// Setter functions

		void				setHitPoints(unsigned int points);
		void				setEnergyPoints(unsigned int points);
		void				setAttackDamage(unsigned int damage);

		/* Overloaded operators */
		// Comparison operators
		// Arithmetic operators
		// Increment and decrement operators

	private:
		/* Attributes */
		const std::string	_name;
		unsigned int		_hit_points;
		unsigned int		_energy_points;
		unsigned int		_attack_damage;

		/* Constructors & Destructors */

		/* Member functions */
};

#endif
