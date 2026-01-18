/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:22:14 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 20:30:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void	Harl::_debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::_warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

/**
 * @brief Maps levels to member functions and executes the match.
 * * Technical Insight: Using (this->*functionList[i])() allows calling
 * a private member function stored in an array.
 */
void	Harl::complain( std::string level ){
	std::string levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// Array of member function pointers
	func		functionList[4] = { &Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error };

	for (int i = 0; i < 4; i++){
		if ( level == levelList[i] ){
			(this->*functionList[i])(); // The specific C++ syntax for calling via pointer
			return ;
		}
	}
	std::cout << "Error : Wrong log level" << std::endl;
}
