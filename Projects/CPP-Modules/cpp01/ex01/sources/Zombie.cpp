/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:51:00 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:28:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/**
 * @brief Default constructor.
 * Initializes an unnamed zombie and prints a creation message.
 */
Zombie::Zombie() : _name("") {
    std::cout << "A new walker has been created !" << std::endl;
}

/**
 * @brief Destructor.
 * Prints a message when the zombie object is destroyed.
 * This is crucial for verifying that heap-allocated zombies are properly deleted.
 */
Zombie::~Zombie( void ) {
    std::cout << "The walker " <<  this->getName() << " has been eliminated !" << std::endl;
}

/**
 * @brief Updates the zombie's name.
 * @param newName The new name string.
 */
void Zombie::setName( const std::string& newName ){
    this->_name = newName;
    std::cout << "The walker has been given the name " << this->getName() << std::endl;
}

/**
 * @brief Returns the name of the zombie.
 * @return std::string The name attribute.
 */
std::string Zombie::getName( void ) const{
    return this->_name;
}

/**
 * @brief Displays the zombie's signature catchphrase.
 */
void Zombie::announce( void ){
    std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
