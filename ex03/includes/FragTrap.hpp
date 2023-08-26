/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:39:35 by nicolas           #+#    #+#             */
/*   Updated: 2023/08/26 14:44:40 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		/* Attributes */

		/* Constructors & Destructors */

		FragTrap(void);
		FragTrap(const std::string name);

		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);

		virtual ~FragTrap(void);

		/* Member functions */

		void	attack(const std::string &target);
		void	highFivesGuys(void);

		/* Overloaded operators */
		// Comparison operators
		// Arithmetic operators
		// Increment and decrement operators

	private:
		/* Attributes */

		/* Constructors & Destructors */

		/* Member functions */

};

#endif
