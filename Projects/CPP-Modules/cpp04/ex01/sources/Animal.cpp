/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:24:18 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:39:04 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal( void ) : _type("pet") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal& other){
    if (this != &other){
        _type = other._type;
    }
    std::cout << "Animal copy assignment operator called"<< std::endl;
    return *this;
}

Animal::Animal( const Animal& other ){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal( void ) {
    std::cout << "Animal destructor called" << std::endl;
}

/**
 * @brief Base class implementation.
 * The makeSound() here is marked 'virtual' in the header, enabling 
 * Dynamic Dispatch (Runtime Polymorphism).
 */
void Animal::makeSound( void) const {
    std::cout << "Animal makes sounds" << std::endl;
}

std::string Animal::getType() const {
    return _type;
}