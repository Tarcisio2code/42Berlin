/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:37:52 by tsilva            #+#    #+#             */
/*   Updated: 2025/04/24 08:38:53 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal( other ){
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other){
    WrongAnimal::operator=(other);
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat( void ){
    std::cout << "WrongCat destructor called" << std::endl;
}

/**
 * @brief Method Hiding (not Overriding).
 * Since the base is not virtual, this method is "hidden" when using 
 * a WrongAnimal* pointer. The compiler will only see the base version.
 */
void WrongCat::makeSound() const{
    std::cout << "Wrong meow wrong meow" << std::endl;
}
