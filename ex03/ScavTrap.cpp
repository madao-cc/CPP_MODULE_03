/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:35:41 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/20 16:01:49 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << _name << " is ready to fight! (By Default)" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << _name << " is ready to fight! (By Name)" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap()
{
	*this = src;
	std::cout << YELLOW << "ScavTrap " << _name << " is ready to fight! (By Copy)" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "ScavTrap " << _name << " doesn't want to play anymore" << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &src)
{
	if (this != &src)
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	return (*this);
}

void	ScavTrap::guardGate()
{
	if (_hitPoints <= 0)
	{
		std::cout << YELLOW << "ScavTrap " << _name << " is dead! Can't guard the gate!" << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "ScavTrap " << _name << " has entered in Gate keeper mode!" << RESET << std::endl;
	std::cout << YELLOW << "After a while, ScavTrap " << _name << " noticed that the gate doesn't exist, and came back to battle mode!" << RESET << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0)
	{
		if (this->_energyPoints > 0)
		{
			
			std::cout << YELLOW << "ScavTrap " << _name << " ferociously lunges at " << target << ", dealing a devastating " << _attackDamage << " points of damage! Watch out..." << RESET << std::endl;
			this->_energyPoints--;
		}
		else
		{
			std::cout << RED << "ScavTrap " << _name << " is out of energy! He cannot attack right now." << RESET << std::endl;
		}
	}
	else
	{
		std::cout << RED << "ScavTrap " << _name << " is out of hit points! He cannot attack right now." << RESET << std::endl;
	}
}
