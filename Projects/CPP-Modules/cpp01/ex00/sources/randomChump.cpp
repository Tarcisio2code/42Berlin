/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:46:34 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:21:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Creates a Zombie object using automatic allocation (Stack).
 * * This function creates a local Zombie object. It is initialized,
 * named, and announces itself. Once the function reaches the end of its 
 * scope, the 'randomZombie' is automatically destroyed, calling its destructor.
 * * @param name The name to be assigned to the temporary Zombie.
 */
void randomChump( std::string name ){
	Zombie	randomZombie;

	randomZombie.setName( name );
	randomZombie.announce();
}
