/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:45:00 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/18 20:26:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Comprehensive test suite for the Fixed class (ex02).
 * * OBJECTIVE: 
 * This main validates arithmetic precision, logical comparisons, 
 * increment/decrement behaviors, and static min/max functions.
 */

#include "../includes/Fixed.hpp"

int main( void ) {

    std::cout << "### Tests from subject ###\n" << std::endl;

    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << "Initial a:      " << a << std::endl;
    std::cout << "Pre-increment:  " << ++a << " (returns updated value)" << std::endl;
    std::cout << "Current a:      " << a << std::endl;
    std::cout << "Post-increment: " << a++ << " (returns previous value)" << std::endl;
    std::cout << "Final a:        " << a << std::endl;

    std::cout << "Value of b:     " << b << " (5.05 * 2)" << std::endl;

    std::cout << "Max(a, b):      " << Fixed::max( a, b ) << std::endl;


    std::cout << "\n## Additional tests ###\n" << std::endl;
    
    Fixed d(5.05f);
    Fixed e(2);
    Fixed f;

    std::cout << "d = " << d << std::endl; 
    std::cout << "e = " << e << std::endl; 
    
    std::cout << std::boolalpha;  // Formats '1/0' as 'true/false' for better readability
    std::cout << "\nComparison operators" << std::endl;
    std::cout << "d > e  : " << (d > e) << std::endl;
    std::cout << "d < e  : " << (d < e) << std::endl;
    std::cout << "d >= e : " << (d >= e) << std::endl;
    std::cout << "d <= e : " << (d <= e) << std::endl;
    std::cout << "d == e : " << (d == e) << std::endl;
    std::cout << "d != e : " << (d != e) << std::endl;

    // Arithmetic operators
    std::cout << "\nArithmetic operators" << std::endl;
    f = d + e;
    std::cout << "d + e = " << f << std::endl;
    f = d - e;
    std::cout << "d - e = " << f << std::endl;
    f = d * e;
    std::cout << "d * e = " << f << std::endl;
    f = d / e;
    std::cout << "d / e = " << f << std::endl;

    /** * @section Bitwise Evolution
     * Monitoring raw bits helps verify that increment/decrement 
     * affects the smallest possible unit (1/256).
     */
    std::cout << "\nIncrement and Decrement operators" << std::endl;
    std::cout << "d : " << d << " raw : " << d.getRawBits() << std::endl;	
    std::cout << "d after pre-increment (++d) : " << ++d << std::endl;
    std::cout << "d : " << d << " raw : " << d.getRawBits() << std::endl;	
    std::cout << "d after post-increment (d++): " << d++ << std::endl;
    std::cout << "d : " << d << " raw : " << d.getRawBits() << std::endl;	
    std::cout << "d after pre-decrement (--d) : " << --d << std::endl;
    std::cout << "d : " << d << " raw : " << d.getRawBits() << std::endl;	
    std::cout << "d after post-decrement (d--): " << d-- << std::endl;
    std::cout << "d : " << d << " raw : " << d.getRawBits() << std::endl;	

    /** * @section Static Member Functions & Const Correctness
     * Testing overloaded static functions with both mutable and const objects.
     * This ensures the class adheres to strict 'const' rules.
     */    
    std::cout << "\nMin and Max functions:" << std::endl;
    std::cout << "min(d, e): " << Fixed::min(d, e) << std::endl;
    std::cout << "max(d, e): " << Fixed::max(d, e) << std::endl;

    std::cout << "\nwith constant values" << std::endl;
    const Fixed g(10);
    const Fixed h(20);
    std::cout << "g = " << g << std::endl; 
    std::cout << "h = " << h << std::endl; 
    std::cout << "min(g, h): " << Fixed::min(g, h) << std::endl;
    std::cout << "max(g, h): " << Fixed::max(g, h) << std::endl;
    std::cout << std::endl;
    return 0;
}
