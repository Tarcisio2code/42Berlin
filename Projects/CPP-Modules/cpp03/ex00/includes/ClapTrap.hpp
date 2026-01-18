/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:50:34 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 12:10:30 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

/**
 * @class ClapTrap
 * @brief Base class for the Trap robot series.
 * * This class implements the core logic for all robots, including health (Hit Points),
 * stamina (Energy Points), and combat capability (Attack Damage).
 */
class ClapTrap
{
	private:
		std::string _name;
		int			_hitpoints;
		int			_energyPoints;
		int			_attackDamage;

	public:
		//Default constructor
		ClapTrap( void );

		//Parametrized Constructor
		ClapTrap( std::string newName );

		//Copy constructor
		ClapTrap(const ClapTrap& other);

		//Copy assignment operator overload
		ClapTrap &operator=(const ClapTrap &other);

		//Destructor
		~ClapTrap( void );

		void attack( std::string const & target );
		void takeDamage( unsigned int amount );
		void beRepaired( unsigned int amount );
		void showPlayerStatus();
		
};

#endif
