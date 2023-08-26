/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:35 by nicolas           #+#    #+#             */
/*   Updated: 2023/08/26 14:32:44 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		/* Attributes */

		/* Constructors & Destructors */

		ScavTrap(void);
		ScavTrap(const std::string name);

		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);

		virtual ~ScavTrap(void);

		/* Member functions */

		void	attack(const std::string &target);
		void	guardGate(void);

		/* Overloaded operators */
		// Comparison operators
		// Arithmetic operators
		// Increment and decrement operators

	private:
		/* Attributes */
		bool	_guarding_gate;

		/* Constructors & Destructors */

		/* Member functions */

};

#endif
