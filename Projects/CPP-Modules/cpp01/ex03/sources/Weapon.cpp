/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:20:17 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:50:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon() {};

Weapon::Weapon( const std::string& weaponType ) : _type(weaponType) {}

Weapon::~Weapon( void ) {};

/**
 * @brief Getter for the weapon type.
 * @return A constant reference to the type string to avoid unnecessary copying.
 */
const std::string& Weapon::getType() const{
    return _type;
}

void Weapon::setType( std::string newType ){
    _type = newType;
}