/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:11:18 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/20 16:13:18 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_Diamond_clap_name"), ScavTrap(), FragTrap()
{
	name = "Default_Diamond";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << name << " is walking by (Default way)" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string nome) : ClapTrap(nome + "_clap_name"), ScavTrap(), FragTrap()
{
	name = nome;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << name << " is walking by (By Name)" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << YELLOW << "DiamondTrap " << name << " is walking by (By Copy)" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "DiamondTrap " << name << " is walking away" << RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src); // This is used because ClapTrap is the base class
		name = src.name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << YELLOW << "My name is " << name << ". Son of " << ClapTrap::getName() << " the \"DESTROYER OF WORLDS\"!"<< RESET << std::endl;
}