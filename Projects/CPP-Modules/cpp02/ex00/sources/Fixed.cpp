/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:02:09 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 10:59:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file Fixed.cpp
 * @brief Implementation of a Fixed-point number class following the Orthodox Canonical Form.
 * * This module introduces how to make a class "well-behaved" by implementing 
 * the four essential member functions: Default Constructor, Copy Constructor, 
 * Copy Assignment Operator, and Destructor.
 */

#include "../includes/Fixed.hpp"

/**
 * @brief Default Constructor
 * Initializes the fixed-point value to 0.
 */
Fixed::Fixed( void ) : _fixedPointNumber(0){
    std::cout << "Default Constructor called" << std::endl;
}

/**
 * @brief Copy Assignment Operator
 * * This is part of the Orthodox Canonical Form. It handles the assignment
 * of an existing object to another existing object (e.g., a = b).
 * * @param other The source object to copy from.
 * @return A reference to the current object (*this) to allow chained assignments (a = b = c).
 */
Fixed& Fixed::operator=( const Fixed& other ){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        setRawBits( other.getRawBits() );
    }
    return *this;
}

/**
 * @brief Copy Constructor
 * * Creates a new object as a copy of an existing one.
 * It uses the assignment operator to avoid logic duplication.
 * @param other The existing object to copy.
 */
Fixed::Fixed( const Fixed& other ){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

/**
 * @brief Sets the raw value of the fixed-point number.
 * @param raw The integer value representing the bits of the fixed-point number.
 */
void Fixed::setRawBits( int const raw ){
    this->_fixedPointNumber = raw;
}

/**
 * @brief Gets the raw value of the fixed-point number.
 * @return The integer value of the bits.
 * @note Marked as 'const' because it does not modify the object's state.
 */
int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointNumber;
}

/**
 * @brief Destructor
 */
Fixed::~Fixed( void ){
    std::cout << "Destructor called" << std::endl;
}