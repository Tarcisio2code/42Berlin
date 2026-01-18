/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:25:30 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 13:44:21 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

/**
 * @brief Default Constructor
 * Due to 'virtual inheritance' in ScavTrap and FragTrap, ClapTrap() 
 * is only called once, avoiding duplicate base subobjects.
 */
DiamondTrap::DiamondTrap( void ) : ClapTrap(), FragTrap(), ScavTrap(), name("player") {
    ClapTrap::_name = "player_clap_name";
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap default constructor: " << ClapTrap::_name << " becomes " << name << " and promoted to Monster Troopers" << std::endl;
}

/**
 * @brief Parameterized Constructor
 * @param newName String used for DiamondTrap identity and transformed for ClapTrap.
 * * Note: We pass the name to the base constructors, but DiamondTrap 
 * maintains its own 'name' variable to satisfy the dual-identity requirement.
 */
DiamondTrap::DiamondTrap( std::string newName ) : ClapTrap(newName + "_clap_name"), FragTrap(newName), ScavTrap(newName), name(newName) {
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 30;
    std::cout << "DiamondTrap parameterized constructor: " << ClapTrap::_name << " designated as " << name << " and promoted to Monster Troopers" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other._name) {
    std::cout << "DiamondTrap copy constructor: " << ClapTrap::_name << " designated as " << name << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap& other) {
    ClapTrap::operator=(other);
	std::cout << "DiamondTrap copy assignment operator: " << name << " reassigned as " << ClapTrap::_name << " and designated as "  << other._name << std::endl;
    name = other._name;
    return *this;
}

DiamondTrap::~DiamondTrap( void ){
    std::cout << "DiamondTrap destructor: " << ClapTrap::_name << " loses his " << name << " designation and was discharged from the Monster Troopers" << std::endl;
}

/**
 * @brief Attack Method Overriding
 * @note This is a strategic choice: although we inherit from both, 
 * we explicitly choose ScavTrap's attack logic to resolve ambiguity.
 */
void DiamondTrap::attack( const std::string& target ){
    ScavTrap::attack(target);
}

/**
 * @brief Special identity method.
 * Prints both the name of the current class and the name of the 
 * ClapTrap base class to prove they are correctly stored as distinct values.
 */
void DiamondTrap::whoAmI( void ){
    std::cout << "DiamondTrap " << name << " reveals its ClapTrap identity: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::showPlayerStatus( void ){
	std::cout << std::right << std::setw(8) << name 
    << ": Hitpoints [ " << std::setw(3) << _hitpoints  
    << " ] | Energy points [ "  << std::setw(3) << this->_energyPoints 
    << " ] | Attack Damage [ " << std::setw(3) << _attackDamage << " ]" 
    << std::endl;
}