/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:02:09 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 10:51:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int					_fixedPointNumber;
		
		/** * @brief Number of fractional bits.
         * * The last 8 bits of the integer are reserved for the decimal part (1/256 precision).
         */
		static const int	_fractionalBits = 8;

	public:
		// Default constructor
		Fixed( void );

		// Destructor
		~Fixed( void );

		// Copy constructor
		Fixed( const Fixed& other );

		// Copy assignment operator overload
		Fixed&	operator=( const Fixed& other );

		// Member functions
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};


#endif