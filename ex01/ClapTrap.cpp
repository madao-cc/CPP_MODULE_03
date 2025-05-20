/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:35:24 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/14 16:33:44 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CYAN << "ClapTrap " << _name << " is created with the Default constructor"  << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << CYAN << "ClapTrap " << _name << " is created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "ClapTrap " << _name << " went home" << RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			
			std::cout << YELLOW << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
			this->_energyPoints--;
		}
		else
		{
			std::cout << RED << "ClapTrap " << _name << " is out of energy! He cannot attack right now." << RESET << std::endl;
		}
	}
	else
	{
		std::cout << RED << "ClapTrap " << _name << " is out of hit points! He cannot attack right now." << RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "Damn! ClapTrap " << _name << " is already fainted! The dead corpse endured the hit" << RESET << std::endl;
	}
	std::cout << RED << "ClapTrap " << _name << " takes " << amount << " points of damage!" << RESET << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << _name << " fainted!" << RESET << std::endl;
		this->_hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << RED << "ClapTrap " << _name << " is already fainted! You cannot repair it." << RESET << std::endl;
		return ;
	}
	else
	{
		std::cout << GREEN << "ClapTrap " << _name << " is repaired for " << amount << " points!" << RESET << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}

std::string const	&ClapTrap::getName() const
{
	return (_name);
}

int const	&ClapTrap::getHitPoints() const
{
	return (_hitPoints);
}

int const	&ClapTrap::getEnergyPoints() const
{
	return (_energyPoints);
}

int const	&ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}