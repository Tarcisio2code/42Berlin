/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:30:23 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 13:34:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

/**
 * @class WrongAnimal
 * @brief Base class designed to demonstrate the absence of dynamic polymorphism.
 * * This class deliberately omits the 'virtual' keyword from the makeSound method. 
 * As a result, C++ will use Static Binding, meaning that a call to makeSound 
 * through a WrongAnimal pointer will always execute this base implementation, 
 * even if the underlying object is a WrongCat.
 */
class WrongAnimal
{
	protected:
		std::string type;

	public:
		//Default constructor
		WrongAnimal( void );

		//Copy constructor
		WrongAnimal( const WrongAnimal& other );

		//Copy assignment operator overload
		WrongAnimal &operator=(const WrongAnimal& ohter);

		//Destructor
		virtual ~WrongAnimal( void );

		void 		makeSound() const;
		std::string getType() const;
};

#endif