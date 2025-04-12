/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:08:24 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/19 12:18:44 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		// Constructor
		DiamondTrap();
		DiamondTrap(std::string name);
		// Copy Constructor
		DiamondTrap(const DiamondTrap &src);
		// Destructor
		~DiamondTrap();
		// Assignation operator
		DiamondTrap	&operator=(const DiamondTrap &src);
		// Member functions
		void	whoAmI();
		void	attack(std::string const & target);
	private:
		std::string	_name;
};

#endif