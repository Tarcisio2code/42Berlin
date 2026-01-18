/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:56:02 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:02:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test suite for Fixed-point conversions and stream overloading.
 * * OBJECTIVE: 
 * This main verifies that integers and floats are correctly converted 
 * to the internal fixed-point representation and back.
 */

 #include "../includes/Fixed.hpp"

int main( void ) {

    Fixed       a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    /** * Tests the 'operator<<'. It should internally call .toFloat() 
     * to display the human-readable decimal value.
     */
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    /** * Tests the .toInt() method, ensuring the fractional bits are 
     * correctly discarded (shifted) to retrieve the original integer.
     */    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    return 0;
}
