/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceFileContents.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:39:54 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 19:58:52 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEFILECONTENTS_HPP
#define REPLACEFILECONTENTS_HPP

#include <fstream>
#include <string>

/**
 * @class ReplaceFileContents
 * @brief Manages the file stream operations and string replacement logic.
 * * This class encapsulates the file handles and strings required to perform
 * a find-and-replace operation across an entire file.
 */
class ReplaceFileContents {
private:
	std::ifstream   _sourceFile;      /**< Input file stream */
    std::ofstream   _destinationFile; /**< Output file stream for .replace file */
    std::string     _file;            /**< Name of the source file */
    std::string     _s1;              /**< String to be replaced */
    std::string     _s2;              /**< String to replace with */

public:
	ReplaceFileContents( char **argumentVector );
	~ReplaceFileContents( void );

	/**
     * @brief Attempts to open the source file and create the destination file.
     * @return true if both files were successfully opened, false otherwise.
     */
	bool	openFiles( void );

	/**
     * @brief Reads the source file line by line, performs replacement, and writes to output.
     * @return true if the process finished successfully.
     */
	bool 	replaceContent( void );
};

#endif
