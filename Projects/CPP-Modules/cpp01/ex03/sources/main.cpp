/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:34:20 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:05:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test suite for HumanA and HumanB weapon ownership models.
 * * OBJECTIVE: 
 * The tests verify that both references (HumanA) and pointers (HumanB) 
 * correctly reflect changes made to the original Weapon object.
 */

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"

int main()
{
    /**
     * @test Test Case 1: HumanA (Reference)
     * Bob is initialized with a reference to 'club'.
     * When 'club' type changes, Bob's attack reflects it because 
     * he is linked to the same memory instance.
     */
    {
        Weapon club = Weapon("crude spiked club");

        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    /**
     * @test Test Case 2: HumanB (Pointer)
     * Jim is initialized without a weapon, then armed via setWeapon.
     * Like HumanA, he points to the memory address of 'club',
     * so updates to the original object are visible to him.
     */
    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}
