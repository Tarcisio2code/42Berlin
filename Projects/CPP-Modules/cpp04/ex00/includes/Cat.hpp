/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:02 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 14:03:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "../includes/Animal.hpp"

/**
 * @class Cat
 * @brief Definition of the Cat class.
 * * Overrides the virtual makeSound method to provide a specific implementation.
 * Inherits the standard interface from Animal to support polymorphic behavior 
 * in collections and function parameters.
 */
class Cat : public Animal
{
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
};

#endif