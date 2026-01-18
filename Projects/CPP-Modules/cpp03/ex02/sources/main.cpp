/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:50:44 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/18 20:52:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test suite for FragTrap.
 * * OBJECTIVE: 
 * Emphasizing inherited vs unique behaviors.
 * Key observations:
 * 1. Base initialization: Notice the FragTrap's higher starting stats (100 HP/100 EP).
 * 2. Inherited logic: Using ClapTrap's takeDamage and beRepaired methods.
 * 3. Unique functionality: Executing the highFivesGuys() method.
 */

#include "../includes/FragTrap.hpp"

int main(){
    
    std::cout << std::endl;
    // The ClapTrap constructor is called BEFORE the FragTrap constructor.
    FragTrap player1( "Clone" );
    player1.showPlayerStatus();
    
    // FragTrap inherits ClapTrap::attack unless overridden.
    std::cout << std::endl;
    player1.attack( "Droid" );
    player1.showPlayerStatus();

    /** * Resilience Test 
     * Testing inherited damage logic 
     * */
    std::cout << std::endl;
    player1.takeDamage(5);
    player1.showPlayerStatus();

    /** Sustainability
     * Testing inherited repair logic.
     */
    std::cout << std::endl;
    player1.beRepaired(5);
    player1.showPlayerStatus();

    std::cout << std::endl;
    player1.highFivesGuys();

    /** * Special Ability
     * Calling the method unique to the FragTrap class.
     */
    std::cout << std::endl;
    std::cout << "** End Game **"<< std::endl;

    // The destructor sequence will fire: FragTrap first, then ClapTrap.
    return 0;
}
