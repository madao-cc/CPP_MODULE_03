/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:45:40 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/03/19 12:32:59 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	std::cout << MAGENTA << "\n=== Testing FragTrap ===" << RESET << std::endl;

	FragTrap frag1("Mewtwo");
	FragTrap frag2("Rayquaza");

	printStats(frag1);
	printStats(frag2);

	frag1.attack("Rayquaza");
	frag2.takeDamage(frag1.getAttackDamage());
	printStats(frag2);

	frag2.beRepaired(50);
	printStats(frag2);

	frag2.highFivesGuys();

	frag2.attack("Mewtwo");
	frag1.takeDamage(frag2.getAttackDamage());
	printStats(frag1);

	frag1.highFivesGuys();

	frag1.attack("Rayquaza");
	frag2.takeDamage(1000);
	printStats(frag2);

	frag2.highFivesGuys();

	std::cout << MAGENTA << "\n=== Testing DiamondTrap ===" << RESET << std::endl;

	DiamondTrap diamond1("Giratina");
	DiamondTrap diamond2("Arceus");

    	printStats(diamond1);
    	printStats(diamond2);

	diamond1.attack("Arceus");
	diamond2.takeDamage(diamond1.getAttackDamage());
	printStats(diamond2);

    	diamond2.beRepaired(20);
    	printStats(diamond2);

	diamond1.whoAmI();
	diamond2.whoAmI();

	diamond2.attack("Giratina");
	diamond1.takeDamage(diamond2.getAttackDamage());
	printStats(diamond1);

	diamond1.attack("Arceus");
	diamond2.takeDamage(1000);
	printStats(diamond2);

	diamond2.whoAmI();

	std::cout << GREEN << "\n=== End of Tests ===" << RESET << std::endl;

	return 0;
}
