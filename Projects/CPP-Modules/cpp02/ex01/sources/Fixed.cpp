/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:02:17 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 11:04:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue(0){
    std::cout << "Default Constructor called" << std::endl;
}

/**
 * @brief Int Constructor
 * Converts an integer to fixed-point by shifting it left by 8 bits.
 * Equivalent to multiplying by 2^8 (256).
 */
Fixed::Fixed( const int integerValue ) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = integerValue << _fractionalBits;
}

/**
 * @brief Float Constructor
 * Converts a float to fixed-point by multiplying it by 2^8 and rounding.
 * Roundf is essential to maintain precision before casting to integer.
 */
Fixed::Fixed( const float floatValue ){
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed& Fixed::operator=( const Fixed& other ){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other){
        setRawBits( other.getRawBits() );
    }
    return *this;
}

Fixed::Fixed( const Fixed& other ){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

void Fixed::setRawBits( int const raw ){
    this->_fixedPointValue = raw;
}

int Fixed::getRawBits( void ) const{
    return this->_fixedPointValue;
}

/**
 * @brief Converts the fixed-point value back to a floating-point number.
 * By casting to float and dividing by 2^8 (256.0), we retrieve the fractional part.
 */
float Fixed::toFloat( void ) const{
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

/**
 * @brief Converts the fixed-point value back to an integer.
 * Shifting right by 8 bits effectively removes the fractional part.
 */
int Fixed::toInt( void ) const{
    return _fixedPointValue >> _fractionalBits;
}

/**
 * @brief Overload of the insertion (<<) operator.
 * Allows the Fixed class to be printed directly via std::cout by 
 * converting it to its floating-point representation.
 */
std::ostream& operator<<( std::ostream&  outputStream, const Fixed& fixed ){
    outputStream << fixed.toFloat();
    return outputStream;
}

Fixed::~Fixed( void ){
    std::cout << "Destructor called" << std::endl;
}
