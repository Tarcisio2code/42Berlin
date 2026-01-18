/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:58:55 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 14:04:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "../includes/Animal.hpp"

/**
 * @class Dog
 * @brief Definition of the Dog class.
 * * Overrides the virtual makeSound method to provide a specific implementation.
 * Inherits the standard interface from Animal to support polymorphic behavior 
 * in collections and function parameters.
 */
class Dog : public Animal
{
	public:
		//Default constructor
		Dog( void );

		//Copy constructor
		Dog( const Dog& other );

		//Copy assignment operator overload
		Dog &operator=(const Dog& other);

		//Destructor
		~Dog( void );

		void makeSound() const;
};

#endif