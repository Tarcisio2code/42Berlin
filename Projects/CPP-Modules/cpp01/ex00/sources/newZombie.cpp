/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:06:52 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:21:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Creates a Zombie object using dynamic allocation (Heap).
 * * This function uses the 'new' keyword to allocate memory for a Zombie.
 * The object created here will persist outside the scope of this function
 * and must be manually destroyed using 'delete' to prevent memory leaks.
 * * @param name The name to be assigned to the new Zombie.
 * @return Zombie* A pointer to the newly allocated Zombie object.
 */
Zombie* newZombie( std::string name )
{
    Zombie* newZombie = new Zombie( name );
    
    return newZombie;
}