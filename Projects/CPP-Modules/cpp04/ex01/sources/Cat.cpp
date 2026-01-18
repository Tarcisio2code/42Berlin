/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:48:08 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:46:21 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

/**
 * @brief Default Constructor
 * Allocates a new Brain object on the heap. This ensures that every Dog 
 * instance starts with its own dedicated memory space for ideas.
 */
Cat::Cat( void ) : Animal(), _brain( new Brain ) {
    _type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

/**
 * @brief Copy Constructor (Deep Copy)
 * Instead of pointing to the same brain as 'other', we allocate a NEW Brain
 * and use Brain's copy constructor to replicate the content. 
 * This prevents the "double-free" crash when both objects are destroyed.
 */
Cat::Cat(const Cat& other) : Animal( other ), _brain( new Brain(*other._brain) ){ 
    std::cout << "Cat copy constructor called" << std::endl;
}

/**
* @brief Copy Assignment Operator
 * 1. Protects against self-assignment.
 * 2. Reuses the Brain's assignment operator to copy data into the existing brain,
 * or allocates a new one if the current pointer is null.
 */
Cat &Cat::operator=(const Cat& other){
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other){    
        Animal::operator=(other);
        if (_brain)
            *_brain = *other._brain;
        else
            _brain = new Brain(*other._brain);
    }
    return *this;
}

/**
 * @brief Destructor
 * Crucial step: Explicitly releases the heap memory allocated for the Brain.
 * This prevents memory leaks.
 */
Cat::~Cat( void ){
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}


void Cat::makeSound() const{
    std::cout << "Meow Meow" << std::endl;
}

/**
 * @brief Delegation to the Brain component.
 * Demonstrates the principle of Encapsulation: the Cat manages the 
 * Brain's interface for the user.
 */
void Cat::setIdea( std::string newIdea, unsigned int index ){
    _brain->setIdea( newIdea, index );
}

std::string Cat::getIdea( unsigned int index ){
    return _brain->getIdea( index );
}