/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:51:13 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:38:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

/**
 * @class Brain
 * @brief Represents the cognitive storage for Animal derivatives.
 * * This class manages a fixed-size array of 100 thoughts (ideas).
 * It is designed to be used as a component within Dog and Cat,
 * serving as the primary subject for testing Deep Copy mechanics.
 */
class Brain
{
	private:
		std::string ideas [100];

	public:
		// Default constructor
		Brain( void );

		// Copy constructor
		Brain( const Brain& other );

		// Copy assignment operator
		Brain& operator=( const Brain& other);

		// Destructor
		~Brain( void );

		/** * @brief Safe accessor and mutator for the ideas array. */
		void 		setIdea( std::string newIdea, unsigned int index );
		std::string getIdea( unsigned int index );
};

#endif