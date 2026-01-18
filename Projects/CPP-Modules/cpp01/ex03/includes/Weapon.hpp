/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:19:58 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:45:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
private:
	std::string	_type;

public:
	Weapon( void ) ;
	Weapon( const std::string& weaponType );
	~Weapon( void );

	/**
     * @brief Returns a constant reference to the weapon type string.
     * Using a reference avoids unnecessary string copying.
     */
	const std::string& getType() const;

	/** @brief Updates the weapon type. */
	void setType( std::string newType );
};

#endif