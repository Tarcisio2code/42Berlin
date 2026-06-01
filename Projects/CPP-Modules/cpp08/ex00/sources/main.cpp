/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:03:32 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/28 14:28:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iterator>
#include <vector>
#include <list>
#include <deque>

template<typename T>
void printContainer(T &container){
    std::cout << "{ ";
    std::copy(container.begin(), container.end(),
              std::ostream_iterator<typename T::value_type>(std::cout, " "));
    std::cout << "}" << std::endl;
}

template<typename T>
void test(T container, int target){
    try{
        typename T::iterator it = easyfind(container, target);
        std::cout << "Value " << target << " found at position : " 
                  << std::distance(container.begin(), it) << std::endl;
    } catch (std::exception &e){
        std::cerr << e.what() << " For the value: " << target << std::endl;
    }
}

int main(){

    {
        std::cout << "---- Testing Vector -----" << std::endl;
        std::vector<int> container;
        container.push_back(1);
        container.push_back(42);
        container.push_back(3);

        printContainer(container);

        test(container, 42);
        test(container, 4);
    }

    {
        std::cout << "\n---- Testing List -----" << std::endl;
        std::list<int> container;
        container.push_back(10);
        container.push_back(20);
        container.push_back(42);

        printContainer(container);
        
        test(container, 42);
        test(container, 30);
    }    
    
    {
        std::cout << "\n---- Testing Deque -----" << std::endl;
        std::deque<int> container;
        container.push_back(42);
        container.push_back(100);
        container.push_back(200);

        printContainer(container);
        
        test(container, 42);
        test(container, 300);
    }

    return (0);
}