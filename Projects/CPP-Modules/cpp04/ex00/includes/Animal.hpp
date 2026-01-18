/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:03:33 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 14:04:03 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

/**
* @class Animal
 * @brief Base class defining the standard interface for all animals.
 * * Provides the foundational structure for polymorphic behavior. The use of virtual 
 * members ensures that derived classes can implement specific behaviors (like sounds) 
 * that are correctly resolved at runtime through a pointer or reference to the base class.
 */
class Animal
{
	protected:
		/** @brief Protected to allow derived classes to set their specific type. */
		std::string _type;

	public:
		//Default constructor
		Animal( void );

		//Copy constructor
		Animal( const Animal& other );

		//Copy assignment operator overload
		Animal &operator=(const Animal& ohter);

		/** * @brief Virtual destructor
         * It ensures that when a derived class (like Dog) is deleted 
         * through an Animal* pointer, the Dog destructor is called first,
         * preventing memory leaks.
         */
		virtual ~Animal( void );

		/** * @brief Virtual method for polymorphic behavior.
         * The 'virtual' keyword tells the compiler to look for the most 
         * derived version of this function at runtime.
         */
		virtual void makeSound() const;
		
		std::string getType() const;
};

#endif