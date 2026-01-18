/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:48:08 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:10:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal() {
    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal( other ){
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other){
    Animal::operator=(other);
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat( void ){
    std::cout << "Cat destructor called" << std::endl;
}

/**
 * @brief Derived class implementation.
 * Because the base method is virtual, this implementation will be 
 * prioritized at runtime when called via an Animal pointer.
 */
void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}
