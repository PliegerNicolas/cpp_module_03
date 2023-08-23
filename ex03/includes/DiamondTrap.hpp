/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:02:15 by nicolas           #+#    #+#             */
/*   Updated: 2023/06/09 13:51:43 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		/* Attributes */

		/* Constructors & Destructors */

		DiamondTrap(void);
		DiamondTrap(const std::string name);

		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);

		~DiamondTrap(void);

		/* Member functions */

		void				attack(const std::string &target);
		void				whoAmI(void);

		// Getter functions

		// Setter functions

		/* Overloaded operators */
		// Comparison operators
		// Arithmetic operators
		// Increment and decrement operators

	private:
		/* Attributes */
		const std::string	_name;

		/* Constructors & Destructors */

		/* Member functions */

};

#endif
