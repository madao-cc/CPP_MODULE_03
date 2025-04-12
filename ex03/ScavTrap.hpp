/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:32:10 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/21 17:33:14 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
	public:
		// Constructor
		ScavTrap();
		ScavTrap(std::string name);
		// Copy Constructor
		ScavTrap(const ScavTrap &src);
		// Destructor
		~ScavTrap();
		// Assignation operator
		ScavTrap	&operator=(const ScavTrap &src);
		// Member functions
		void	guardGate();
};

#endif