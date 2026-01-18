/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:05:35 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:41:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain( void ) {
    std::cout << "Brain default constructor called" << std::endl;
}

/**
 * @brief Copy Constructor
 * Performs a Deep Copy of the ideas array. This ensures that when a 
 * new Brain is created from an existing one, they do not share memory.
 */
Brain::Brain( const Brain& other ) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i){
        ideas[i] = other.ideas[i];
    }
}

/**
 * @brief Copy Assignment Operator
 * Overwrites the current Brain's data with another's. 
 * The 'if (this != &other)' check is crucial to prevent issues with self-assignment.
 */
Brain &Brain::operator=( const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;    
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i){
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain( void ) {
    std::cout << "Brain destructor called" << std::endl;
}

/**
 * @brief Set Idea with boundary protection.
 * @param index Must be between 0 and 99.
 */
void Brain::setIdea( std::string newIdea, unsigned int index ){
    if (index < 100)
        ideas[index] = newIdea;    
}

/**
 * @brief Get Idea with boundary protection.
 * Provides a fallback string if the index is out of range.
 */
std::string Brain::getIdea( unsigned int index ){
    if (index < 100)
        return ideas[index];
    return "no idea";    
}
