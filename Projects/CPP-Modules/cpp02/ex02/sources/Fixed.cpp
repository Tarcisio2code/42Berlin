/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:44:42 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 11:13:47 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue(0){}

/**
 * @brief Int Constructor
 * Converts an integer to fixed-point by shifting it left by 8 bits.
 * Equivalent to multiplying by 2^8 (256).
 */
Fixed::Fixed( const int integerValue ) {
    this->_fixedPointValue = integerValue << _fractionalBits;
}

/**
 * @brief Float Constructor
 * Converts a float to fixed-point by multiplying it by 2^8 and rounding.
 * Roundf is essential to maintain precision before casting to integer.
 */
Fixed::Fixed( const float floatValue ){
    this->_fixedPointValue = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed& Fixed::operator=( const Fixed& other ){
    if (this != &other){
        setRawBits( other.getRawBits() );
    }
    return *this;
}

Fixed::Fixed( const Fixed& other ){
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

/* --- Comparison Operators --- */
/**
 * @note Comparison operators are marked 'const' as they do not modify the object.
 * We compare the raw bits directly for maximum efficiency (O(1)).
 */
bool Fixed::operator>( const Fixed& other )const {
    return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<( const Fixed& other )const {
    return (this->_fixedPointValue < other._fixedPointValue);
}

/**
 * @brief Logical reuse of existing operators.
 * By defining >= in terms of <, we ensure consistency and reduce logic duplication.
 */
bool Fixed::operator>=( const Fixed& other )const {
    return !(*this < other);
}

bool Fixed::operator<=( const Fixed& other )const {
    return !(*this > other);
}

bool Fixed::operator==( const Fixed& other )const {
    return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=( const Fixed& other )const {
    return !(*this == other);
}

/* --- Arithmetic Operators --- */
/**
 * @note Arithmetic operations convert to float first to handle precision 
 * and overflow/underflow safely before converting back to fixed-point.
 */
Fixed Fixed::operator+( const Fixed& other )const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-( const Fixed& other )const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*( const Fixed& other )const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/( const Fixed& other )const {
    return Fixed(this->toFloat() / other.toFloat());
}

/* --- Increment/Decrement Operators --- */
/**
 * @brief Pre-increment operator (++f).
 * Increments the raw bits by 1 (the smallest epsilon in fixed-point).
 * @return Reference to the current object.
 */
Fixed& Fixed::operator++( void ){
    this->_fixedPointValue += 1;
    return *this;
}

/**
 * @brief Post-increment operator (f++).
 * @param int Dummy parameter used by the compiler to distinguish from pre-increment.
 * @return A copy of the object BEFORE the increment.
 */
Fixed Fixed::operator++( int ){
    Fixed tmp = *this;
    this->_fixedPointValue += 1;
    return tmp;
}

Fixed& Fixed::operator--( void ){
    this->_fixedPointValue -= 1;
    return *this;
}

Fixed Fixed::operator--( int ){
    Fixed tmp = *this;
    this->_fixedPointValue -=1;
    return tmp;
}

/* --- Min / Max Static Member Functions --- */
/**
 * @brief Static methods to find the minimum/maximum between two Fixed objects.
 * Overloaded for both mutable and constant references.
 */
Fixed& Fixed::min( Fixed& firstValue, Fixed& secondValue ){
    if (firstValue < secondValue)
        return (firstValue);
    return (secondValue);
}

const Fixed& Fixed::min( const Fixed& firstValue, const Fixed& secondValue ){
    if (firstValue < secondValue)
        return (firstValue);
    return (secondValue);
}

Fixed& Fixed::max( Fixed& firstValue, Fixed& secondValue ){
    if (firstValue > secondValue)
        return (firstValue);
    return (secondValue);
}

const Fixed& Fixed::max( const Fixed& firstValue, const Fixed& secondValue ){
    if (firstValue > secondValue)
        return (firstValue);
    return (secondValue);
}

Fixed::~Fixed( void ){}

