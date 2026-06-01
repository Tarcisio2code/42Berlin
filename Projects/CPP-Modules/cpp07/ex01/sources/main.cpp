/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:57:15 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/20 15:21:17 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

template <typename T>
void increment(T &value){
    value++;
}

template <typename T>
void printAny(const T &value){
    std::cout << value << " " << std::endl;
}

int main(){
    std::cout << "=== Integer ===" << std::endl;
    {    
        int newArr[] = {1, 2, 3};
        iter(newArr, 3, increment<int>);
        iter(newArr, 3, printAny<int>);
    }

    std::cout << "\n=== Double ===" << std::endl;
    {
        double newArr[] = {1.63425, 2.71828, 3.14159};
        iter(newArr, 3, printAny<double>);
    }

    std::cout << "\n=== Char ===" << std::endl;
    {    
        char newArr[] = {'a', 'b', 'c'};
        iter(newArr, 3, printAny<char>);
    }

    std::cout << "\n=== String ===" << std::endl;
    {    
        const std::string newArr[] = {"Hello", "42", "Berlin"};
        iter(newArr, 3, printAny<std::string>);
    }

}
