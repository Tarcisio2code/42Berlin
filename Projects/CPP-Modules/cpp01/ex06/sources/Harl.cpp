/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:51:02 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 20:38:37 by tsilva           ###   ########.fr       */
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
 * @brief Harl filtering logic using switch-case fallthrough.
 */
void	Harl::complain( std::string level ){
	std::string levelList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			indexLevel = 0;

	while (indexLevel < 4 && (level != levelList[indexLevel]))
		indexLevel++;

	switch (indexLevel)
	{
		case 0:
			std::cout << "[ " << levelList[0] << " ]" << std::endl;
			_debug();
			std::cout << std::endl;
			/* fallthrough */
		case 1:
			std::cout << "[ " << levelList[1] << " ]" << std::endl;
			_info();
			std::cout << std::endl;
			/* fallthrough */
		case 2:
			std::cout << "[ " << levelList[2] << " ]" << std::endl;
			_warning();
			std::cout << std::endl;
			/* fallthrough */
		case 3:
			std::cout << "[ " << levelList[3] << " ]" << std::endl;
			_error();
			std::cout << std::endl;
			break;			
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
