/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 13:00:32 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:04:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Entry point for the Zombie program.
 * * OBJECTIVE: 
 * This main function illustrates two types of memory management:
 * 1. Heap Allocation: Creating a zombie that lives until manually deleted.
 * 2. Stack Allocation: Creating a zombie that lives only within a function scope.
 * * @return int Returns 0 on success.
 */

#include "../includes/Zombie.hpp"

int main() {
	
	// Heap Allocation
	Zombie* zombie1 = newZombie( "Zombie1" );
	zombie1->announce();
	
	std::cout << std::endl;
	
	// Stack Allocation
	randomChump( "Chump1" );

	delete zombie1;

	return 0;
}
