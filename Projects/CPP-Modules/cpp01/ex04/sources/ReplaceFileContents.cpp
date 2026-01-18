/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFileContents.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:49:22 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 20:05:34 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Utils.hpp"
#include "../includes/ReplaceFileContents.hpp"

/**
 * @brief Constructor using an initializer list for efficiency.
 */
ReplaceFileContents::ReplaceFileContents( char **argumentVector )
	: _file( argumentVector[1] ), _s1( argumentVector[2] ), _s2( argumentVector[3] ) {}

/**
 * @brief Opens the streams and performs safety checks.
 * @note .c_str() is used for compatibility with C++98 fstream::open.
 */
bool ReplaceFileContents::openFiles(){
	_sourceFile.open(  this->_file.c_str() );
	if ( !_sourceFile )
		return errorMessage( "Could not open the source file" );

	// Check if the file has content to avoid unnecessary processing	
	else if ( _sourceFile.peek() == std::ifstream::traits_type::eof() )
		return errorMessage( "The source file is empty" );

	_destinationFile.open( (this->_file + ".replace").c_str() );
	if ( !_destinationFile )
		return errorMessage( "Could not open or create the destination file" );
	return true;
}

/**
 * @brief Reads the source file line by line and writes the processed content.
 * Ensures that the newline structure is preserved correctly.
 */
bool ReplaceFileContents::replaceContent() {
	std::string line;
	std::string newLine;

	while (std::getline(_sourceFile, line)) {
		if (!_sourceFile)
			return errorMessage( "Fail to open the source file" );

		newLine = replaceOccurences(line, this->_s1, this->_s2);

		if (!_destinationFile)
			return errorMessage( "Fail to write to destination file" );

		_destinationFile << newLine;

		// Only append newline if it's not the end of the file to maintain exact structure
		if (!_sourceFile.eof())
			_destinationFile << ('\n');
	}
	return true;
}

ReplaceFileContents::~ReplaceFileContents() {
	_sourceFile.close();
	_destinationFile.close();
}
