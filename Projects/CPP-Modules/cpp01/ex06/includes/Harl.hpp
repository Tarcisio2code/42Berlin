/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:50:40 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 20:33:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HALL_HPP
#define HALL_HPP

#include	<iostream>
#include	<string>

/**
 * @class Harl
 * @brief A class that complains based on log levels using function pointers.
 * * Design Pattern: This approach replaces a chain of if-else statements
 * with a jump table (array of pointers), making the code more scalable 
 * and easier to maintain.
 */
class Harl
{
private:
	void	_debug( void );
	void	_info( void );
	void	_warning( void );
	void	_error( void );

public:

	Harl();
	~Harl();

	/**
     * @brief Directs the complaint to the appropriate private method.
     * @param level The log level (DEBUG, INFO, WARNING, ERROR).
     */
	void	complain( std::string level );

	typedef	void (Harl::*func)();
};

#endif