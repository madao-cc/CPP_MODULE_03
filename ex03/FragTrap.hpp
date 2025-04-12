/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:05:03 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/19 12:13:19 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	public:
		// Constructor
		FragTrap();
		FragTrap(std::string name);
		// Copy Constructor
		FragTrap(const FragTrap &src);
		// Destructor
		~FragTrap();
		// Assignation operator
		FragTrap	&operator=(const FragTrap &src);
		// Member functions
		void	highFivesGuys(void);
};

#endif