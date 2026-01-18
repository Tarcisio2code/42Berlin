/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:58:55 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:33:59 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

/**
 * @class Dog
 * @brief Derived class using Composition to handle complex data.
 * * * This class introduces a pointer to a Brain object, demonstrating:
 * 1. Composition: An Animal "has-a" Brain.
 * 2. Dynamic Allocation: The Brain must be allocated on the heap during construction.
 * 3. Deep Copy Requirement: To prevent double-free errors or shared state between
 * separate objects, the Copy Constructor and Assignment Operator must 
 * perform a full duplication of the Brain object.
 */
class Dog : public Animal
{
	private:
		/** @brief Pointer to a dynamically allocated Brain object. */
		Brain* _brain;
	
	public:
		//Default constructor
		Dog( void );

		//Copy constructor
		Dog( const Dog& other );

		//Copy assignment operator overload
		Dog &operator=(const Dog& other);

		//Destructor
		~Dog( void );

		void 		makeSound() const;

		/** @brief Interface to interact with the Brain's data without exposing the pointer. */
		void 		setIdea( std::string newIdea, unsigned int index );
		std::string getIdea( unsigned int index );
};

#endif