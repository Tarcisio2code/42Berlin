/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:46:34 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:30:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Allocates an array of N Zombie objects on the heap.
 * * 1. It uses 'new[]' to allocate a single block of memory for N Zombies.
 * 2. It iterates through the array to set a unique name for each zombie.
 * 3. The name is modified by appending the index to differentiate the walkers.
 * * @param N The number of zombies to be created.
 * @param name The base name for the zombies.
 * @return Zombie* A pointer to the first element of the zombie array.
 */
Zombie* zombieHorde( int N, std::string name ){
	// This calls the default constructor for each element
	Zombie* newHorde = new Zombie[N];
	for (int i = 0; i < N; i++){
		newHorde[i].setName( name + static_cast<char>((i + 1) + 48) );
	}
	return newHorde;
}