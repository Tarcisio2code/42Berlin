/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:54 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:51:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanB.hpp"

/**
 * @brief Constructor for HumanB.
 * Initializes the name and sets the weapon pointer to NULL,
 * as HumanB may start unarmed.
 */
HumanB::HumanB( const std::string& newName ) : _name(newName), _weapon(NULL) {}

HumanB::~HumanB() {}

/**
 * @brief Performs an attack. 
 * Since _weapon is a pointer, we must verify it is not NULL before 
 * dereferencing it to avoid a segmentation fault.
 */
void HumanB::attack(){
    if ( this->_weapon ) {
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } else {
        std::cout << this->_name << " has no weapon" << std::endl;
    }
}

void HumanB::setWeapon( Weapon& weaponType ){
    this->_weapon = &weaponType;
}
