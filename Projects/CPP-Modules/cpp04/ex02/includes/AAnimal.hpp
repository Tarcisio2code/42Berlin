/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:03:33 by tsilva            #+#    #+#             */
/*   Updated: 2025/04/25 18:00:21 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

/**
 * @class AAnimal
 * @brief Abstract Base Class (Interface) for the Animal hierarchy.
 * * * KEY CONCEPT: Abstract Classes & Pure Virtual Functions.
 * By assigning '= 0' to makeSound(), this class becomes abstract. 
 * It is now impossible to instantiate an object of type AAnimal directly 
 * (e.g., 'new AAnimal()' will fail to compile).
 * This forces all derived classes (Dog/Cat) to provide their own implementation 
 * of makeSound, ensuring no "generic" animal can exist.
 */
class AAnimal
{
	protected:
		/** @brief Protected to allow derived classes to set their specific type. */
		std::string type;

	public:
		//Default constructor
		AAnimal( void );

		//Copy constructor
		AAnimal( const AAnimal& other );

		//Copy assignment operator overload
		AAnimal &operator=(const AAnimal& ohter);

		/** * @brief Virtual destructor remains vital for proper cleanup 
         * of derived classes (Dog/Cat) and their Brains. */
		virtual ~AAnimal( void );
		
		/** * @brief Pure Virtual Function.
         * Makes the class abstract. This acts as a mandatory requirement 
         * for any concrete subclass.
         */
		virtual void makeSound() const = 0;

		std::string getType() const;
};

#endif
