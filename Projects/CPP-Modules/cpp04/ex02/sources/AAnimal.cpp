/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:24:18 by tsilva            #+#    #+#             */
/*   Updated: 2025/04/25 18:02:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

AAnimal::AAnimal( void ) : type("pet") {
    std::cout << "Animal default constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal& other){
    if (this != &other){
        type = other.type;
    }
    std::cout << "Animal copy assignment operator called"<< std::endl;
    return *this;
}

AAnimal::AAnimal( const AAnimal& other ){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

AAnimal::~AAnimal( void ) {
    std::cout << "Animal destructor called" << std::endl;
}

/**
 * @brief Abstract class implementation.
 * makeSound() is a Pure Virtual Function (= 0). This implementation 
 * exists only as a fallback or for documentation, as AAnimal 
 * cannot be instantiated. Derived classes MUST override this 
 * to become concrete.
 */
void AAnimal::makeSound( void) const {
    std::cout << "Animal makes sounds" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}