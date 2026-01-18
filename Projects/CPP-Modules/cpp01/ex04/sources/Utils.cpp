/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:35:41 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 20:15:14 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"

bool	errorMessage( std::string message ){
	std::cerr << "Error : " << message << std::endl;
	return false;

}

bool	onlySpaces( const std::string& str ){
    for ( size_t i = 0; i < str.size(); ++i ){
		if ( !std::isspace(static_cast<unsigned char>(str[i])) ){
			return false;
		}
	};
	return true;
}

/**
 * @brief Validates CLI arguments.
 * Ensures the program doesn't crash with null or empty inputs.
 */
bool	validEntry( int argc, char **argv ){
		std::string fileName;
		std::string	string1;
	
		if ( argc != 4 )
			return ( errorMessage("Invalid number of arguments") );

		fileName = argv[1];
		string1 = argv[2];
		if ( fileName.size() == 0 || string1.size() == 0 )
			return ( errorMessage("Wrong argument") );
		return ( true );
}

/**
 * @brief Efficient string replacement algorithm.
 * Uses std::string::find and buffer concatenation to replace all occurrences.
 * @note Complexity: O(n) where n is the length of originalString.
 */
std::string	replaceOccurences( std::string& originalString, std::string& oldString, std::string& newString ){
	std::string	replacedString;
	size_t		pos = 0, lastPos = 0;
		
    while ( (pos = originalString.find(oldString, lastPos) ) != std::string::npos ) {
        // Append the part before the match
		replacedString.append( originalString, lastPos, pos - lastPos ) ;
		// Append the replacement
        replacedString.append( newString );
 		// Move the cursor past the match
		lastPos = pos + oldString.length();
    }
	// Append the remaining part of the string
	replacedString.append( originalString.substr(lastPos) );
	return replacedString;
}