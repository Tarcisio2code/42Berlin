/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:02:09 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:06:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test suite for the Orthodox Canonical Form implementation.
 * * OBJECTIVE: 
 * This main serves as a trace to verify the exact sequence of 
 * constructor and assignment operator calls.
 */

#include "../includes/Fixed.hpp"

int main(){   
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    /** * Accesses the raw bits of each object to prove the copy was successful.
     * All three should output '0' in this specific exercise.
     */
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    /** * When main returns, destructors for c, b, and a will be called 
     * in the reverse order of their creation (Stack behavior).
     */
}
