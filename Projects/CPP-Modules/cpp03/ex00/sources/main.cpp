/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:50:44 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:07:09 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Basic battle simulation to test ClapTrap's state machine.
 * * OBJECTIVE: 
 * This sequence verifies the transitions between healthy, damaged, 
 * and destroyed states, ensuring that action limits are enforced.
 */

#include "../includes/ClapTrap.hpp"

int main(){

    // Creates a ClapTrap with 10 HP, 10 Energy, and 0 Attack.
    ClapTrap player1( "Clone" );
    player1.showPlayerStatus();
 
    // Attacking should consume 1 Energy Point.
    std::cout << std::endl;
    player1.attack( "Droid" );
    player1.showPlayerStatus();

    /** * Receiving 10 damage should bring HP to 0.
     * This tests the underflow protection in takeDamage().
     */
    std::cout << std::endl;
    player1.takeDamage(10);
    player1.showPlayerStatus();

    /** * A ClapTrap with 0 HP should not be able to repair itself.
     * This verifies that the "is alive" check is working correctly.
     */
    std::cout << std::endl;
    player1.beRepaired(5);
    player1.showPlayerStatus();

    std::cout << std::endl;
    std::cout << "** End Game **"<< std::endl;

}