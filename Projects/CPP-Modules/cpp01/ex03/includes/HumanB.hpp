/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:26:40 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:47:27 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

/**
 * @class HumanB
 * @brief Represents a human that can be unarmed.
 * * @note Design Choice: Uses a POINTER (Weapon*).
 * Unlike HumanA, HumanB can start without a weapon (pointer set to NULL).
 * The weapon can also be changed or removed at any time during the object's life.
 */
class HumanB{
private:
	std::string	_name;
	Weapon*		_weapon;

public:
	HumanB( const std::string& newName );
	~HumanB( void );

	/** @brief Displays an attack message, checking if a weapon exists first. */
	void attack();

	void setWeapon( Weapon& weaponType );
};

#endif