/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:51:16 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:02:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief HarlFilter.
 * * OBJECTIVE: A demonstration of log filtering using switch-case fallthrough.
 * Unlike ex05, where Harl only complained about a SPECIFIC level using 
 * function pointers, ex06 introduces a "Minimum Level" filter. 
 * * Using a switch statement with intentional fallthrough, Harl will now 
 * display the selected level AND all subsequent levels of higher importance.
 */

#include "../includes/Harl.hpp"

int main (int argc, char **argv){

	if (argc != 2){
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	
	Harl	harl;
	harl.complain(argv[1]);
}