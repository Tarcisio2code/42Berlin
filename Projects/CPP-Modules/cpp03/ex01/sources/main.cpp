/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:50:44 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:07:19 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test bench for ScavTrap .
 * * OBJECTIVE: 
 * Inheritance and specialized behavior.
 * Key observations for this test:
 * 1. Constructor Chaining: Observe the order (ClapTrap created, then ScavTrap).
 * 2. Polymorphism: ScavTrap uses its own 'attack' but inherits 'takeDamage'.
 * 3. State Management: Verifying the increased HP (100) and EP (50) stats.
 */

#include "../includes/ScavTrap.hpp"

int main(){
    ScavTrap player1( "Clone" );
    player1.showPlayerStatus();

    std::cout << std::endl;
    player1.attack( "Droid" );
    player1.showPlayerStatus();

    /** ScavTrap does not redefine takeDamage or beRepaired; 
     * it reuses the logic from ClapTrap flawlessly.
     */
    std::cout << std::endl;
    player1.takeDamage(5);
    player1.showPlayerStatus();

    std::cout << std::endl;
    player1.beRepaired(5);
    player1.showPlayerStatus();

    std::cout << std::endl;
    player1.guardGate();

    std::cout << std::endl;
    std::cout << "** End Game **"<< std::endl;

    /** * Chained Destruction
     * Reverse order: ScavTrap is destroyed first, then ClapTrap.
     */
    return 0;
}
