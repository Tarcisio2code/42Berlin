/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:44:54 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/13 13:13:18 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Functions.hpp"

Base * generate(void){
    int rnd = std::rand() % 3;

    if (rnd == 0)
        return new A;
    if (rnd == 1) 
        return new B;
    return new C;
}

void identify(Base *p){
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p){
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type B" << std::endl;
        return;
    } catch (const std::exception& e) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type C" << std::endl;
        return;
    } catch (const std::exception& e) {}
    std::cout << "Unknown type" << std::endl;
}
