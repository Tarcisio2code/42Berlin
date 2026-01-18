/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:32:06 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/16 14:07:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "../includes/WrongAnimal.hpp"

/**
 * @class WrongCat
 * @brief Derived class that illustrates the failure of method overriding without virtual functions.
 * * Although this class defines its own makeSound() method, it cannot be called 
 * polymorphically through a WrongAnimal pointer because the base method is not virtual. 
 * This results in "method hiding" rather than true "method overriding."
 */
class WrongCat : public WrongAnimal
{
	public:
		//Default constructor
		WrongCat( void );

		//Copy constructor
		WrongCat(const WrongCat& other);

		//Copy assignment operator overload
		WrongCat &operator=(const WrongCat& other);

		//Destructor
		~WrongCat( void );

		void makeSound() const;

};

#endif