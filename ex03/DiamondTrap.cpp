/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 12:11:18 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/19 12:20:55 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_Diamond_clap_trap"), ScavTrap(), FragTrap()
{
	_name = "Default_Diamond";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << _name << " is walking by (Default way)" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name), FragTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << _name << " is walking by (By Name)" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	*this = src;
	std::cout << YELLOW << "DiamondTrap " << _name << " is walking by (By Copy)" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "DiamondTrap " << _name << " is walking away" << RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << YELLOW << "My name is " << _name << ". Son of " << ClapTrap::getName() << " the \"DESTROYER OF WORLDS\"!"<< RESET << std::endl;
}