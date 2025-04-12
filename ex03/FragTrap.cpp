/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:04:44 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/18 12:27:20 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << YELLOW << "FragTrap " << _name << " randomly appeared in battle (By Default)" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << YELLOW << "FragTrap " << _name << " randomly appeared in battle (By Name)" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap()
{
	*this = src;
	std::cout << YELLOW << "FragTrap " << _name << " randomly appeared in battle (By Copy)" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "In the same random way FragTrap " << _name << " appeared, he has now disappeared from battle" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &src)
{
	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (_hitPoints <= 0)
	{
		std::cout << YELLOW << "FragTrap " << _name << " is dead! Can't give high fives!" << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "FragTrap " << _name << " is asking for high fives!" << RESET << std::endl;
	std::cout << std::endl << "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨" << std::endl;
	std::cout << YELLOW << "A divine glow surrounds the FragTrap as it raises its hand for a high five. The battlefield falls silent. All other Traps drop their weapons, mesmerized by the sheer brilliance of the gesture. In this moment, the FragTrap is no longer a mere machine — it is a god among Traps, uniting them all under the sacred call for high fives..." << RESET << std::endl;
	std::cout << "✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨✨" << std::endl << std::endl;
	std::cout << YELLOW << "Everyone is giving high fives to FragTrap " << _name << "!" << RESET << std::endl;
}