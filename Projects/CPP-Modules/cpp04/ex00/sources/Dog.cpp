/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:04:15 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:11:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal() {
    _type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal( other ) {
    std::cout << "Dog copy constructor called" << std::endl;    
}

Dog &Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    std::cout << "Dog copy assignment operator called" << std::endl;     
    return *this;   
}

Dog::~Dog( void ){
    std::cout << "Dog Destructor called" << std::endl;    
}

/**
 * @brief Derived class implementation.
 * Because the base method is virtual, this implementation will be 
 * prioritized at runtime when called via an Animal pointer.
 */
void Dog::makeSound() const {
    std::cout << "woof woof woof" << std::endl;
}
