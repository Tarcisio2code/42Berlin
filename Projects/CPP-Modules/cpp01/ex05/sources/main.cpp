/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:59:19 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/18 13:44:55 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Test bench for the Harl class.
 * * OBJECTIVE: 
 * Verifies that the automated complaint system correctly maps string levels
 * to their respective private member functions using pointers.
 */

#include "../includes/Harl.hpp"

int main (void){
	Harl	harl;

	std::cout << "** DEBUG level **" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;	
	
	std::cout << "** INFO level **" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;	
	
	std::cout << "** WARNING level **" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;	
	
	std::cout << "** ERROR level **" << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;	

	std::cout << "** Wrong level **" << std::endl;	
	harl.complain("WRONG");
	std::cout << std::endl;	
}