/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:41:04 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:26:51 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

/**
 * @class Zombie
 * @brief Represents a zombie character.
 * * In this exercise, zombies are often created in groups (hordes) 
 * using a single allocation.
 */
class Zombie
{
	private:
		std::string _name;

	public:
		Zombie( void );
		~Zombie( void );
		
		void announce( void );
		
		void setName( const std::string& newName );
		std::string getName( void ) const;
};

/**
 * @brief Allocates a horde of N zombies in a single contiguous memory block.
 * * @param N The number of zombies to create.
 * @param name The name to be assigned to all zombies in the horde.
 * @return Zombie* A pointer to the first zombie of the array.
 * @note This memory MUST be freed using 'delete []' to avoid leaks.
 */
Zombie* zombieHorde( int N, std::string name );

#endif
