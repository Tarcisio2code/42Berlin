/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:26:40 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:46:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

/**
 * @class HumanA
 * @brief Represents a human that is armed at all times.
 * * @note Design Choice: Uses a REFERENCE (Weapon&).
 * Since a reference cannot be null and must be initialized at construction,
 * HumanA is guaranteed to always have a valid weapon during its entire lifetime.
 */
class HumanA{
private:
	std::string	_name;
	Weapon&		_weapon;

public:
	/**
     * @brief Constructor for HumanA.
     * Note that the weapon is passed by reference and initialized via an 
     * initializer list, as references cannot be assigned later.
     */
	HumanA( const std::string& newName, Weapon& weaponType );
	~HumanA( void );

	void attack();
};

#endif