/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:45:40 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/18 11:43:40 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void printStats(const ClapTrap &clapTrap)
{
	std::cout << BLUE << "Stats for " << clapTrap.getName() << ":" << RESET << std::endl;
	std::cout << GREEN << "Hit Points: " << clapTrap.getHitPoints() << RESET << std::endl;
	std::cout << GREEN << "Energy Points: " << clapTrap.getEnergyPoints() << RESET << std::endl;
	std::cout << GREEN << "Attack Damage: " << clapTrap.getAttackDamage() << RESET << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << MAGENTA << "=== Testing ClapTrap ===" << RESET << std::endl;

	ClapTrap clap1("Charizard");
	ClapTrap clap2("Blastoise");

	printStats(clap1);
	printStats(clap2);

	clap1.attack("Blastoise");
	clap2.takeDamage(5);
	printStats(clap2);

	clap2.beRepaired(3);
	printStats(clap2);

	clap2.attack("Charizard");
	clap1.takeDamage(8);
	printStats(clap1);

	clap1.attack("Blastoise");
	clap2.takeDamage(10);
	printStats(clap2);

	std::cout << MAGENTA << "\n=== Testing ScavTrap ===" << RESET << std::endl;

	ScavTrap scav1("Pikachu");
	ScavTrap scav2("Eevee");

	printStats(scav1);
	printStats(scav2);

	scav1.attack("Eevee");
	scav2.takeDamage(scav1.getAttackDamage());
	printStats(scav2);

	scav2.beRepaired(10);
	printStats(scav2);

	scav2.guardGate();

	scav2.attack("Pikachu");
	scav1.takeDamage(scav2.getAttackDamage());
	printStats(scav1);

	scav1.guardGate();

	scav1.attack("Eevee");
	scav2.takeDamage(1000);
	printStats(scav2);

	scav2.guardGate();

	std::cout << GREEN << "\n=== End of Tests ===" << RESET << std::endl;

	return 0;
}
