/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:10:24 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/21 16:44:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"

template <typename T> 
void    testFunctions(T a, T b){
        std::cout << "original  : ( a = " << a << ", b = " << b << " )" << std::endl;;
        ::swap( a, b );
        std::cout << "after swap: ( a = " << a << ", b = " << b << " )" << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
}

int main( void ) {
    std::cout << "=== Integer ===" << std::endl;
    {    
        int a = 2;
        int b = 3;

        testFunctions(a, b);
    }

    std::cout << "\n=== Char ===" << std::endl;
    {
        char a = 'X';
        char b = 'z';

        testFunctions(a, b);
    }

    std::cout << "\n=== Double ===" << std::endl;
    {
        double a = 3.14159;
        double b = 2.71828;

        testFunctions(a, b);
    }    

    std::cout << "\n=== String ===" << std::endl;
    {
        std::string a = "bigger";
        std::string b = "smaller";

        testFunctions(a, b);
    }

    return 0;
}