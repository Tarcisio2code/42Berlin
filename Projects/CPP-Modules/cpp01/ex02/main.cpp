/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:27:47 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:05:42 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Demonstration of the differences between Pointers and References in C++.
* * OBJECTIVE: 
 * This exercise highlights that while both pointers and references can access
 * the same memory address, their syntax and behavior differ.
 */

#include <iostream>
#include <string>

int main(){
// The original variable
    std::string     stringVAR = "HI THIS IS BRAIN";
    
    /** * A pointer: A variable that stores the memory address of another variable.
     * Can be reassigned or be null.
     */
    std::string* stringPTR = &stringVAR;
    
    /** * A reference: An alias for an existing variable. 
     * Once initialized, it cannot be changed to refer to another object.
     */
    std::string&    stringREF = stringVAR;

    /** * Section 1: Memory Addresses
     * Demonstrates that all three point to the exact same location in memory.
     */
    std::cout << "Printing the memory address..." << std::endl;
    std::cout << "The memory address of the stringVAR  : " << &stringVAR << std::endl;
    std::cout << "The memory address held by stringPTR : " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF : " << &stringREF << std::endl;

    std::cout << std::endl;

    /** * Section 2: Values
     * Demonstrates how to access the value:
     * - Directly (stringVAR)
     * - By dereferencing (stringPTR)
     * - Via alias (stringREF)
     */
    std::cout << "Printing the value..." << std::endl;
    std::cout << "The value of the string stringVAR : " << stringVAR << std::endl;
    std::cout << "The value pointed to by stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF : " << stringREF << std::endl;

    return 0;
}