/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:41:01 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/20 17:48:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main()
{
    std::cout << "=== Integer ===" << std::endl;
    Array<int> intArray(3);
    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    for (unsigned int i = 0; i < intArray.size(); i++)
        std::cout << intArray[i] << std::endl;

    std::cout << "\n=== Double ===" << std::endl;
    Array<double> doubleArray(3);
    doubleArray[0] = 1.63425;
    doubleArray[1] = 2.71828;
    doubleArray[2] = 3.14159;
    const Array<double> constArray(doubleArray);
    for (unsigned int i = 0; i < constArray.size(); i++)
        std::cout << constArray[i] << std::endl;

    std::cout << "\n=== String ===" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "42";
    stringArray[2] = "Berlin";
    for (unsigned int i = 0; i < stringArray.size(); i++)
        std::cout << stringArray[i] << std::endl;

    std::cout << "\n=== Out of bounds test ===" << std::endl;
    try{
        doubleArray[3] = 42.1;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Empty array test ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Array size: " << emptyArray.size() << std::endl;

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Array<int> original(2);
    original[0] = 1;
    Array<int> copy; 
    copy = original; // use copy assign operator
    copy[0] = 42;
    std::cout << "Original[0]: " << original[0] << "(should be 42)" << std::endl;
    std::cout << "Copy[0]: " << copy[0] << " (should be 42)" << std::endl;

    return 0;
}