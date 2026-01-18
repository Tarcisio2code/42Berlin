/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:35:25 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:11:27 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongPet") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other){
        type = other.type;
    }
    std::cout << "WrongAnimal copy assignment operator called"<< std::endl;
    return *this;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

/**
 * @brief Base implementation WITHOUT virtual dispatch.
 * Calls to this method are resolved at compile-time (Static Binding).
 */
void WrongAnimal::makeSound( void) const {
    std::cout << "WrongAnimal makes sounds" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}