/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:42:36 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 13:29:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

/**
 * @brief Default Constructor
 * Initializes FragTrap with its specific profile: 100 HP, 100 EP, 30 AD.
 */
FragTrap::FragTrap( void ) : ClapTrap() {
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor: " << _name << " promoted to High-Five Troopers" << std::endl;
}

/**
 * @brief Parameterized Constructor
 * Leverages the base constructor for naming, then sets FragTrap-specific stats.
 */
FragTrap::FragTrap( std::string newName ) : ClapTrap( newName ) {
	_hitpoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap parameterized constructor: " << _name << " promoted to High-Five Troopers" << std::endl;
}

/**
 * @brief Copy Constructor
 * Delegates attribute copying to the ClapTrap base class.
 */
FragTrap::FragTrap( const FragTrap& other ) : ClapTrap( other ){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/**
 * @brief Copy Assignment Operator
 * Reuses the base class assignment logic to ensure all inherited 
 * attributes are properly updated.
 */
FragTrap &FragTrap::operator=(const FragTrap &other){
	ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator cloned the player: " << _name << " as a high-fiver." << std::endl;
	return *this;
}

FragTrap::~FragTrap( void ){
	std::cout << "FragTrap destructor: " << _name << " was discharged from the High-Five Troopers" << std::endl;
}

/**
 * @brief Unique special ability for FragTrap.
 * Unlike ScavTrap's combat-oriented guardGate, FragTrap has a 
 * social interaction method, showcasing class-specific personality.
 */
void FragTrap::highFivesGuys( void ){
	std::cout << "FragTrap " << _name << " requests a Positive high five! ✋" << std::endl;	
}
