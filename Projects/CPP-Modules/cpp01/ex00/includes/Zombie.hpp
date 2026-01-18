/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:41:04 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:13:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

/**
 * @class Zombie
 * @brief Represents a zombie character that can announce itself.
 */
class Zombie
{
	private:
		std::string _name;

	public:
		Zombie( void );
		~Zombie( void );
		
		/**
         * @brief Prints the zombie's name followed by a braiiiiiiinnnzzzZ... message.
         */
		void announce( void );
		
		void setName( const std::string& newName );
		std::string getName( void ) const;

		Zombie( std::string name );
};

/**
 * @brief Creates a new zombie on the HEAP.
 * @param name The name of the zombie.
 * @return Zombie* A pointer to the newly allocated zombie. 
 * @note This zombie must be manually deleted to avoid memory leaks.
 */
Zombie* newZombie( std::string name );

/**
 * @brief Creates a zombie on the STACK.
 * @param name The name of the zombie.
 * @note This zombie will be automatically destroyed when the function returns.
 */
void randomChump( std::string name );

#endif
