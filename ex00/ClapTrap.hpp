/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:30:45 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/17 16:56:38 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

class	ClapTrap
{
	private:
		std::string	_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;
	public:
		// Constructor
		ClapTrap();
		ClapTrap(std::string name);
		// Copy Constructor
		ClapTrap(const ClapTrap &src);
		// Destructor
		~ClapTrap();
		// Assignation operator
		ClapTrap	&operator=(const ClapTrap &src);
		// Getters
		std::string const	&getName() const;
		int const		&getHitPoints() const;
		int const		&getEnergyPoints() const;
		int const		&getAttackDamage() const;
		// Setters

		// Member functions
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif