/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:37:54 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:50:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"
#include "../includes/HumanA.hpp"

/**
 * @brief Constructor for HumanA using an Initializer List.
 * @note Because _weapon is a reference, it MUST be initialized here.
 * It cannot be assigned inside the constructor body.
 */
HumanA::HumanA( const std::string& newName, Weapon& weaponType ) : _name(newName), _weapon(weaponType) {}

HumanA::~HumanA() {}

/**
 * @brief Performs an attack. Since _weapon is a reference, 
 * we know it is always valid and skip the null check.
 */
void HumanA::attack(){
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
