/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:02 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 14:06:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

/**
 * @class Cat
 * @brief Derived class using Composition to handle complex data.
 * * * This class introduces a pointer to a Brain object, demonstrating:
 * 1. Composition: An Animal "has-a" Brain.
 * 2. Dynamic Allocation: The Brain must be allocated on the heap during construction.
 * 3. Deep Copy Requirement: To prevent double-free errors or shared state between
 * separate objects, the Copy Constructor and Assignment Operator must 
 * perform a full duplication of the Brain object.
 */
class Cat : public Animal
{
	private:
		/** @brief Pointer to a dynamically allocated Brain object. */
		Brain* _brain;

	public:
		//Default constructor
		Cat( void );

		//Copy constructor
		Cat(const Cat& other);

		//Copy assignment operator overload
		Cat &operator=(const Cat& other);

		//Destructor
		~Cat( void );

		void makeSound() const;

		/** @brief Interface to interact with the Brain's data without exposing the pointer. */
		void 		setIdea( std::string newIdea, unsigned int index );
		std::string getIdea( unsigned int index );
};

#endif