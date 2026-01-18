/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:13:29 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 17:57:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

/**
 * @brief Modes for displaying contact information.
 */
enum	e_display_mode {
		BASIC, /**< Table format (truncated) */
		FULL   /**< Complete contact details */
};

/**
 * @brief Types of messages for UI feedback.
 */
enum	e_message_type {
		GREETING_MSG,
		SINGLE_MSG,
		ERROR_MSG,
		HEADER_MSG,
		INPUT_MSG
};

/**
 * @brief Fields representing contact information categories.
 */
enum	e_field {
		INDEX,
		FIRST_NAME,
		LAST_NAME,
		NICKNAME,
		PHONE_NUMBER,
		DARKEST_SECRET
};

/**
 * @brief Types of input validation required.
 */
enum 	e_validation_type {
    	NUM_VALIDATION,
    	ALPHA_VALIDATION,
		NO_VALIDATION	/**< Any non-empty input allowed */
};

/**
 * @class Contact
 * @brief Represents a single contact in the phonebook.
 */
class	Contact {
	private:
		int				_index;
		std::string		_firstName;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;
		std::string 	_darkestSecret;
		
		// Truncates a string to 10 characters and adds a dot if longer.
		std::string		_truncateString( std::string str ) const;

	public:
		Contact( void );
		~Contact( void );

		void		setContact( int index, std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret );
		std::string	getContact( e_field field ) const;
		void		displayContact( e_display_mode mode ) const;
};

/**
 * @class PhoneBook
 * @brief Manages an array of 8 contacts and handles user interaction.
 */
class	PhoneBook {
	private:
		static const int	_contactLimit = 8;
		int					_contactCount;
		bool				_onlySpaces( const std::string& str ) const;
		bool 				_isValidChar(char c, e_validation_type type) const;
		void 				_getValidEntry(std::string filedText, std::string* entry, e_validation_type type);
		bool				_displayContactList( void ) const;
		Contact				_contacts[_contactLimit];

	public:
		PhoneBook( void );
		~PhoneBook( void );

		void	displayMenu( void ) const;
		void	displayMessage( std::string message, e_message_type type ) const;
		void	addContact( void );
		void	searchContact( void ) const;
};

#endif
