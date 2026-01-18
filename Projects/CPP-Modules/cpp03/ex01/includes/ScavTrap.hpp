/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:21:20 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 12:16:14 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @class ScavTrap
 * @brief Definition of the ScavTrap class, inheriting from ClapTrap.
 * Public Inheritance: ScavTrap "is-a" ClapTrap.
 * Method Overriding: Redefining the attack logic specifically for this derived class.
 * Extended Functionality: Adding unique behaviors (guardGate) not present in the base class.
 */
class ScavTrap : public ClapTrap
{
	public:
		//Default constructor
		ScavTrap( void );

		//Parametrized Constructor
		ScavTrap( std::string newName );

		//Copy constructor
		ScavTrap( const ScavTrap& other );

		//Copy assignment operator overload
		ScavTrap &operator=(const ScavTrap &other);

		//Destructor
		~ScavTrap( void );
		
		void attack( std::string const & target );
		void guardGate();
};

#endif