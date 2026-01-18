/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 09:42:15 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 12:22:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

/**
 * @class FragTrap
 * @brief Second specialized derivative of ClapTrap.
 * * FragTrap represents a different balance of stats (high HP, high Attack) 
 * and introduces a social interaction method. This further demonstrates 
 * how the base class can be extended into diverse archetypes.
 */
class FragTrap : public ClapTrap
{	
	public:
		//Default constructor
		FragTrap( void );

		//Parametrized Constructor
		FragTrap( std::string newName );

		//Copy constructor
		FragTrap( const FragTrap& other );

		//Copy assignment operator overload
		FragTrap &operator=(const FragTrap &other);

		//Destructor
		~FragTrap( void );

		void highFivesGuys( void );
};

#endif
