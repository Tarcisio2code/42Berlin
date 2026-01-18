/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:50:44 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:07:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Ultimate test for DiamondTrap.
 * * OBJECTIVE:
 * Verifying Multiple Inheritance integration.
 * This sequence proves that DiamondTrap correctly accesses:
 * 1. Its own unique methods (whoAmI).
 * 2. ScavTrap's methods (attack, guardGate).
 * 3. FragTrap's methods (highFivesGuys).
 * 4. ClapTrap's methods (takeDamage, beRepaired).
 */

 #include "../includes/DiamondTrap.hpp"

int main(){
    DiamondTrap player1( "Clone" );    
    player1.showPlayerStatus();

    /** * Ambiguity Resolution
     *  This calls ScavTrap::attack as required by the exercise, 
     * even though the object is also part FragTrap.
     */
    std::cout << std::endl;
    player1.attack( "Droid" );
    player1.showPlayerStatus();

    /** * Base Class Functionality
     * Testing the logic inherited from the common grandfather (ClapTrap).
     * Virtual inheritance ensures there is only ONE instance of ClapTrap attributes.
     */
    std::cout << std::endl;
    player1.takeDamage(50);
    player1.showPlayerStatus();

    std::cout << std::endl;
    player1.beRepaired(50);
    player1.showPlayerStatus();

    /** * Multi-Parent Abilities
     * Testing methods from both sides of the family tree:
     * - whoAmI: DiamondTrap's specific identity logic.
     * - highFivesGuys: Inherited from FragTrap.
     * - guardGate: Inherited from ScavTrap.
     */
    std::cout << std::endl;
    player1.whoAmI();
    player1.highFivesGuys();
    player1.guardGate();

    std::cout << std::endl;
    std::cout << "** End Game **"<< std::endl;

    /** * The destructors will fire in reverse order: 
     * Diamond -> Scav -> Frag -> Clap.
     */
    return 0;
}