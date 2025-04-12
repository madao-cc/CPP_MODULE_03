/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:45:40 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/17 17:06:27 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void printClapTrapStats(const ClapTrap &clapTrap1, const ClapTrap &clapTrap2)
{
	std::cout << BLUE << "At this moment, your " << clapTrap1.getName() << " has " << clapTrap1.getHitPoints() << " hit points, " << clapTrap1.getEnergyPoints() << " energy points and " << clapTrap1.getAttackDamage() << " attack damage." << RESET << std::endl;
	
	std::cout << BLUE << "And the other " << clapTrap2.getName() << " has " << clapTrap2.getHitPoints() << " hit points, " << clapTrap2.getEnergyPoints() << " energy points and " << clapTrap2.getAttackDamage() << " attack damage." << RESET << std::endl;
}

int	main()
{
	ClapTrap	clapTrap("Charizard");
	ClapTrap	clapTrap2("Blastoise");

	std::cout << GREEN << "Your " << clapTrap.getName() << " has " << clapTrap.getHitPoints() << " hit points, " << clapTrap.getEnergyPoints() << " energy points and " << clapTrap.getAttackDamage() << " attack damage." << RESET << std::endl;
	
	std::cout << GREEN << "You encounter a wild " << clapTrap2.getName() << " with " << clapTrap2.getHitPoints() << " hit points, " << clapTrap2.getEnergyPoints() << " energy points and " << clapTrap2.getAttackDamage() << " attack damage." << RESET << std::endl;
	
	clapTrap.attack("ClapTrap2");
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap2.takeDamage(5);
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap2.beRepaired(3);
	printClapTrapStats(clapTrap, clapTrap2);

	clapTrap2.attack("ClapTrap");
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap.takeDamage(8);
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap.attack("ClapTrap2");
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap2.takeDamage(10);
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap.attack("ClapTrap2");
	printClapTrapStats(clapTrap, clapTrap2);
	clapTrap2.takeDamage(1000);
	
	std::cout << GREEN << "BLASTOISE FAINTED! PLEASE STOP! Thank you :)" << RESET << std::endl;
	return (0);
}
