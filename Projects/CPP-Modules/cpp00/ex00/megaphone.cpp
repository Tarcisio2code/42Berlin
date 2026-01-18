/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:00:59 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:09:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * * OBJECTIVE: 
 * Takes command line arguments and prints them in uppercase. 
 * If no arguments are provided, it outputs a default feedback noise message.
 * * @param argc The number of command line arguments.
 * @param argv The array of command line argument strings.
 * @return int Returns 0 on success.
 */

#include <iostream>
#include <string>


int main (int argc, char **argv)
{
	std::string	stringToConvert;
	std::size_t	stringLength = 0;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		for (int currArg = 1; currArg < argc; currArg++){
			stringToConvert = argv[currArg];
			stringLength = stringToConvert.length();
			
			/** Convert each character of the current string to uppercase. */
			for (std::size_t i = 0; i < stringLength; i++){
				std::cout << static_cast<char>(std::toupper(stringToConvert[i]));
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
