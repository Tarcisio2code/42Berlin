/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:30:15 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 12:00:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

/**
 * @brief Default Constructor
 * Note the explicit call to ClapTrap() in the initializer list.
 * Values are then updated to ScavTrap specific stats (100 HP, 50 EP, 20 AD).
 */
ScavTrap::ScavTrap( void ) : ClapTrap() {
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor: " << _name << " promoted to Gatekeeper Troopers" << std::endl;
}

/**
 * @brief Parameterized Constructor
 * Passes the name directly to the base class constructor to handle initialization.
 */
ScavTrap::ScavTrap( std::string newName ) : ClapTrap( newName ) {
	_hitpoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap parameterized constructor: " << _name << " promoted to Gatekeeper Troopers" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap( other ) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/** 
 * @brief Copy Assignment Operator
 * @note Technical Highlight: Explicitly call the base class assignment operator 
 * to handle inherited attributes, maintaining clean and modular code.
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator cloned the player: " << _name << " as a GateKeeper." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap( void ){
	std::cout << "ScavTrap destructor: " << _name << " was discharged from the Gatekeeper Troopers" << std::endl;
}

/**
 * @brief Overridden Attack Method
 * Same logic as base but identifies as a "ScavTrap" in output.
 */
void ScavTrap::attack(const std::string& target){
	if (_energyPoints > 0 && _hitpoints > 0){
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << _name << " has no hitpoints or energy to attack!" << std::endl;
}

/**
 * @brief Specific Member Function
 * Adds unique functionality to the derived class.
 */
void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << _name << " has entered Gate keeper mode" << std::endl;
}
