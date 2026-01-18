/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:01:36 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 11:07:45 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
		int					_fixedPointValue;

		/** * @brief Number of fractional bits.
         * * The last 8 bits of the integer are reserved for the decimal part (1/256 precision).
         */
		static const int	_fractionalBits = 8;

	public:
		// Default constructor
		Fixed( void );
		
		// Copy constructor
		Fixed( const Fixed& other );

		// Copy assignment operator overload
		Fixed&	operator=( const Fixed& other );

		// Parametrized integer constructor
		Fixed( const int integerValue );

		// Parametrized float constructor
		Fixed( const float floatValue );

		// Destructor
		~Fixed( void );

		// Member functions
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

/**
 * @brief Overload of the insertion (<<) operator for std::ostream.
 * * This is a non-member function that allows the Fixed class to be used with 
 * standard output streams (like std::cout). It facilitates seamless integration 
 * with C++ I/O by converting the fixed-point value to its floating-point 
 * representation before outputting.
 * * @param outputStream Reference to the output stream (lhs).
 * @param fixed Reference to the Fixed object to be printed (rhs).
 * @return std::ostream& Reference to the stream to allow for operator chaining.
 */
std::ostream& operator<<( std::ostream&  outputStream, const Fixed& fixed );

#endif