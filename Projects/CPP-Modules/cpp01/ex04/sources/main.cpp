/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:35:41 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:06:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Entry point for the Sed-style string replacement program.
 * * OBJECTIVE: 
 * This program demonstrates:
 * 1. Robust command-line argument validation.
 * 2. Object-Oriented approach to file stream management.
 * 3. Error-handling via return codes (1 for failure, 0 for success).
 */


#include "../includes/ReplaceFileContents.hpp"
#include "../includes/Utils.hpp"

int	main( int argc, char** argv ){
	
	if ( !validEntry( argc, argv ) )
		return 1;

	// Encapsulates the filename, s1, and s2 within the class.
	ReplaceFileContents	replaceFileContents( argv );

	/** * Attempt to open the source file and create the .replace file.
     * All logic for existence checks and empty files is handled here.
     */
	if ( !replaceFileContents.openFiles() )
		return 1;

	// Reads line by line, replaces occurrences, and writes to the destination.
	if ( !replaceFileContents.replaceContent() )
		return 1;

	/** * Cleanup is handled automatically by the ReplaceFileContents destructor,
     * which closes the file streams when the object goes out of scope.
     */
	return 0;
}
