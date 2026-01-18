/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:58:55 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 14:09:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../includes/AAnimal.hpp"
#include "../includes/Brain.hpp"

/**
 * @class Dog
 * @brief Concrete implementation of the AAnimal abstract interface.
 * * * This class fulfills the contract defined by AAnimal and uses Composition:
 * 1. Implementation: Provides the required 'makeSound' logic, making this a Concrete Class.
 * 2. Composition: An Animal "has-a" Brain (component-based design).
 * 3. Dynamic Allocation: The Brain is allocated on the heap, requiring careful lifecycle management.
 * 4. Deep Copy: Implements full data duplication in the Copy Constructor and Assignment Operator
 * to ensure independent states and prevent memory corruption (double-free).
 */
class Dog : public AAnimal
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
		void 		setIdea( std::string newIdea, unsigned int index );

		/** @brief Interface to interact with the Brain's data without exposing the pointer. */
		std::string getIdea( unsigned int index );
};

#endif
