/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:35:05 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 20:00:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

//#include <string>
#include <iostream>

bool		errorMessage( std::string message );

/** @brief Checks if a string consists only of whitespace characters. */
bool		onlySpaces( const std::string& str );

/** * @brief Validates the command line arguments provided to the program.
 * Checks for the correct number of arguments and non-empty strings.
 */
bool        validEntry( int argc, char **argv );

/**
 * @brief Core logic for finding and replacing all occurrences of s1 with s2 in a string.
 * @param originalString The full content of the file.
 * @param oldString The target substring.
 * @param newString The replacement substring.
 * @return A new string with all replacements applied.
 */
std::string	replaceOccurences( std::string& originalString, std::string& oldsString, std::string& newString );

#endif