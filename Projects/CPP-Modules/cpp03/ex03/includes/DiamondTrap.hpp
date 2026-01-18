/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:10:01 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 13:41:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

/**
 * @class DiamondTrap
* @brief Definition of the DiamondTrap class - Solving the Diamond Problem.
 * * This class inherits from both FragTrap and ScavTrap, which in turn both 
 * inherit from ClapTrap. 
 * * Key Concept: To avoid having two copies of ClapTrap inside DiamondTrap, 
 * the parent classes must use 'virtual inheritance'.
 */
class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		/** @brief Unique name for DiamondTrap, distinct from ClapTrap::_name. */
		std::string name;

	public:
		//Default constructor
		DiamondTrap( void );

		//Parametrized Constructor
		DiamondTrap( std::string newName );

		//Copy constructor
		DiamondTrap( const DiamondTrap& other );

		//Copy assignment operator overload
		DiamondTrap &operator=( const DiamondTrap& other);
		
		//Destructor
		~DiamondTrap( void );

		/** * @brief Uses ScavTrap's attack specifically.
         * Explicitly overriding to resolve the ambiguity between FragTrap and ScavTrap.
         */
		void attack( const std::string& target );

		/** * @brief Special method to display both its own name and its base name.
         * Demonstrates the relationship between the derived and parent identity.
         */
		void whoAmI( void );

		/** @brief Helper to verify if stats were correctly inherited from both parents. */
		void showPlayerStatus( void );	 
};

#endif
