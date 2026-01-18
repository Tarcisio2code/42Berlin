/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:50:39 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 13:31:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("player"), _hitpoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor: " << _name << " enter the game" << std::endl;
}

ClapTrap::ClapTrap( std::string newName ) : _name(newName), _hitpoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap parameterized constructor: " << _name << " enter the game" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << "ClapTrap copy constructor: starting cloning " << other._name << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
    if (this != &other){
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap copy assignment operator: " << _name << " was cloned" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap( void ){
    std::cout << "ClapTrap destructor: " << _name << " left the game with " << std::setw(3) << _energyPoints << " Energy points" << std::endl;
}

/**
 * @brief Logic for attacking a target.
 * * Requires both Hit Points (alive) and Energy Points (stamina).
 * * Consumes 1 Energy Point.
 */
void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitpoints > 0)
    {
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has no hitpoints or energy to attack!" << std::endl;
}

/**
 * @brief Logic for receiving damage.
 * * Prevents Hit Points from dropping below 0 (underflow protection).
 */
void ClapTrap::takeDamage( unsigned int amount ){
    if (_hitpoints > 0){
        if ((int)amount >= _hitpoints)
            _hitpoints = 0;
        else
            _hitpoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has no hit points to take damage!" << std::endl;
}

/**
 * @brief Logic for self-repairing.
 * * Requires Hit Points > 0 (cannot repair if destroyed) and Energy > 0.
 * * Consumes 1 Energy Point.
 */
void ClapTrap::beRepaired( unsigned int amount ){
    if (_energyPoints > 0 && _hitpoints > 0){
        _hitpoints += amount;
        _energyPoints-- ;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " can't repair himself!" << std::endl;
}

/**
 * @brief Utility function to display the robot's current stats.
 * Uses <iomanip> for clean, aligned terminal output.
 */
void ClapTrap::showPlayerStatus( void ){
	std::cout << std::right << std::setw(8) << _name 
    << ": Hitpoints [ " << std::setw(3) << _hitpoints  
    << " ] | Energy points [ "  << std::setw(3) << _energyPoints 
    << " ] | Attack Damage [ " << std::setw(3) << _attackDamage << " ]" 
    << std::endl;
}
