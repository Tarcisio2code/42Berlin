/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:00:32 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:05:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Entry point to test the zombieHorde function.
 * * OBJECTIVE: 
 * This program demonstrates:
 * 1. Allocation of an array of objects on the heap using a single pointer.
 * 2. Iteration through the array to invoke member functions.
 * 3. Proper deallocation of an array to prevent memory leaks.
 * * @return int Returns 0 on success.
 */

#include "../includes/Zombie.hpp"

int main() {
	int hordeSize = 5;

	/** * ZombieHorde returns a pointer to the first element
     * of a contiguous block of 'hordeSize' Zombie objects.
     */
	Zombie* firstHorde = zombieHorde(hordeSize, "Walker");

	// Demonstrate access to a specific zombie via the pointer
	std::cout << "The first zombie is " << firstHorde->getName() << std::endl;

	for (int z=0; z < hordeSize; z++){
		firstHorde[z].announce();
	}

	/** * Correct Deallocation:
     * This ensures the destructor is called for EVERY zombie in the horde,
     * not just the first one.
     */
	delete [] firstHorde;

	return 0;
}
