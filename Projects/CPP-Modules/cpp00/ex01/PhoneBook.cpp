/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:29:51 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/14 18:16:11 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * @brief Construct a new PhoneBook object and initialize contact count.
 */
PhoneBook::PhoneBook() : _contactCount(0) {}

/**
 * @brief Construct a new Contact object and initialize all fields to empty.
 */
Contact::Contact() 
    : _index(0),
      _firstName(""),
      _lastName(""),
      _nickName(""),
      _phoneNumber(""),
      _darkestSecret("")
{}

/**
 * @brief Destroy the PhoneBook object and display a goodbye message.
 */
PhoneBook::~PhoneBook(){
	displayMessage("Goodbye !", GREETING_MSG);
	std::cout << std::endl;
}

Contact::~Contact(){};

/**
 * @brief Assigns values to all contact attributes.
 */
void Contact::setContact(int index, std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret) {
	_index = index;
	_firstName = firstName;
	_lastName = lastName;
	_nickName = nickName;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

/**
 * @brief Returns the value of a specific field as a string.
 * @param field The enum identifying the requested field.
 * * @return std::string The content of the field. For the INDEX field, 
 * the integer is converted to a string.
 */
std::string	Contact::getContact(e_field field) const {
	std::ostringstream	oss;
	switch (field){
		// Use ostringstream to safely convert the integer index to a string
		case INDEX: oss << _index; return oss.str();
		case FIRST_NAME: return _firstName;
		case LAST_NAME: return _lastName;
		case NICKNAME: return _nickName;
		case PHONE_NUMBER: return _phoneNumber;
		case DARKEST_SECRET: return _darkestSecret;
		default: return "";
	}
}

/**
 * @brief Formats a string to 10 characters, replacing the last with a dot if longer.
 */
std::string Contact::_truncateString(std::string str) const {
    const int maxLength = 10;
    if (str.length() >= maxLength)
        return str.substr(0, maxLength - 1) + ".";
    else
        return str;
}

/**
 * @brief Displays the contact in either basic table row or full detailed list.
 */
void Contact::displayContact(e_display_mode mode) const {
	if (mode == BASIC){
		std::cout << std::setw(8) << std::right << "" << std::setw(10) << getContact(INDEX) <<  " | "; 
		std::cout << std::setw(10) << std::right << _truncateString(getContact(FIRST_NAME)) << " | ";
		std::cout << std::setw(10) << std::right << _truncateString(getContact(LAST_NAME)) << " | ";
		std::cout << std::setw(10) << std::right << _truncateString(getContact(NICKNAME)) << std::endl;
	}
	else if (mode == FULL){
		std::cout << std::setw(16) << "" << "Index.........: " << getContact(INDEX) << std::endl << std::endl; 
		std::cout << std::setw(16) << "" << "First Name....: " << getContact(FIRST_NAME) << std::endl << std::endl;
		std::cout << std::setw(16) << "" << "Last Name.....: " << getContact(LAST_NAME) << std::endl << std::endl;
		std::cout << std::setw(16) << "" << "Nick Name.....: " << getContact(NICKNAME) << std::endl << std::endl;
		std::cout << std::setw(16) << "" << "Phone Number..: " << getContact(PHONE_NUMBER) << std::endl << std::endl;
		std::cout << std::setw(16) << "" << "Darkest Secret: " << getContact(DARKEST_SECRET) << std::endl;
	}
}

/**
 * @brief Handles UI message formatting based on message type (headers, errors, etc).
 */
void PhoneBook::displayMessage(std::string message, e_message_type type) const{
	std::cout << std::endl;
	if (type == INPUT_MSG){
		std::cout << std::setw(8) << std::right << "" << message;
		return ;
	}
	else if (type == SINGLE_MSG)
	        std::cout << std::right << "" << std::setw(57) << message;
	else if (type == ERROR_MSG)
		std::cout << std::right << "" << std::setw(57) << ("ERROR : " + message);
	else if (type == HEADER_MSG)
		std::cout << std::setw(8) << std::right << "" << message << " " << std::string((48 - message.length()), '-') << std::endl;
	else if (type == GREETING_MSG){
		std::cout << std::setw(8) << std::right << "" << std::string(49, '*') << std::endl;
		std::cout << std::setw(8) << std::right << "" << "*" << std::string(((49 - message.length())/2), ' ') << message;
		std::cout << std::setw((48 - (((49 - message.length()) / 2) + message.length()))) << "*" << std::endl;
		std::cout << std::setw(8) << std::right << "" << std::string(49, '*') << std::endl;
	}
	std::cout << std::endl;
}

/**
 * @brief Displays the main command menu.
 */
void PhoneBook::displayMenu() const{
	displayMessage("OPTIONS", HEADER_MSG);
	std::cout << std::setw(16) << "" << "ADD    - to add a new contact." << std::endl;
	std::cout << std::setw(16) << "" << "SEARCH - to search for a contact." << std::endl;
	std::cout << std::setw(16) << "" << "EXIT   - to exit the program." << std::endl;
	displayMessage("Enter your option: ", INPUT_MSG);
}

/**
 * @brief Validates if a string contains only whitespace.
 */
bool PhoneBook::_onlySpaces(const std::string& str) const {
    for (size_t i = 0; i < str.size(); ++i){
		if (!std::isspace(str[i])){
			return false;
		}
	};
	return true;
}

/**
 * @brief Checks if a character matches the required validation type.
 */
bool PhoneBook::_isValidChar(char c, e_validation_type type) const {
    if (type == NUM_VALIDATION)
        return std::isdigit(c) || c == '(' || c == ')' || c == ' ';
    else if (type == ALPHA_VALIDATION)
        return std::isalpha(c) || c == ' ';
	else if (type == NO_VALIDATION)
		return true;
	else
		return false;
}

/**
 * @brief Loops until the user provides a non-empty, valid entry for a field.
 */
void PhoneBook::_getValidEntry(std::string filedText, std::string* entry, e_validation_type type) {
    std::string input;
    bool isValid;
    
    do {
        isValid = true;
		std::cout << std::setw(16) << "" << filedText;
        std::getline(std::cin, input);
        
        if (input.empty() || _onlySpaces(input)) {
            displayMessage("Field cannot be empty", ERROR_MSG);
			std::cout << std::endl;
            isValid = false;
            continue;
        }
        
        for (size_t i = 0; i < input.length(); ++i) {
            if (!_isValidChar(input[i], type)) {
                if (type == NUM_VALIDATION)
                	displayMessage("Numbers, () and spaces only", ERROR_MSG);
           	 	else
                	displayMessage("Letters and spaces only", ERROR_MSG);
				std::cout << std::endl;
                isValid = false;
                break;
            }
        }
    } while (!isValid);
    
    *entry = input;
}

/**
 * @brief Prompts user for contact info and adds it to the list, overwriting the oldest if full.
 */
void PhoneBook::addContact(){
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	int			oldestContact = _contactCount % _contactLimit;

	displayMessage("ADD NEW CONTACT", HEADER_MSG);

    _getValidEntry("First name....: ", &firstName, ALPHA_VALIDATION);  
    std::cout << std::endl;
    _getValidEntry("Last name.....: ", &lastName, ALPHA_VALIDATION);
    std::cout << std::endl;
    _getValidEntry("Nick name.....: ", &nickName, NO_VALIDATION);
    std::cout << std::endl;
    _getValidEntry("Phone number..: ", &phoneNumber, NUM_VALIDATION);
    std::cout << std::endl;
    _getValidEntry("Darkest secret: ", &darkestSecret, NO_VALIDATION);

	_contacts[oldestContact].setContact(oldestContact + 1, firstName, lastName, nickName, phoneNumber, darkestSecret);
	_contactCount++;

	displayMessage("Contact added successfully !", SINGLE_MSG);
}

/**
 * @brief Prints the list of existing contacts in a table format.
 * @return false if no contacts exist.
 */
bool PhoneBook::_displayContactList() const {
	int lastContact = std::min(_contactCount, static_cast<int>(_contactLimit));

	if (lastContact == 0){
		displayMessage("No contacts found", SINGLE_MSG);
		return false;
	}	
	std::cout << std::setw(8) << "" << "     Index | First Name |  Last Name |  Nick Name" << std::endl;
	std::cout << std::setw(8) << "" << "---------- + ---------- + ---------- + ----------" << std::endl;
	for (int i = 0; i < lastContact; i++){
		_contacts[i].displayContact(BASIC);
	}
	return true;
}

/**
 * @brief Lists contacts and prompts user for an index to show full details.
 */
void PhoneBook::searchContact() const {
	int	indexOfContact = 0;
	int lastContact = std::min(_contactCount, static_cast<int>(_contactLimit));

	displayMessage("SEARCH CONTACT", HEADER_MSG);
	if (!_displayContactList())
		return;
	displayMessage("Enter the contact index: ", INPUT_MSG);	
	if (std::cin.peek() == '\n' || std::cin.peek() == '\t'){
        std::cin.ignore();
        displayMessage("No input !", ERROR_MSG);
        return;
    }	
	std::cin >> indexOfContact;
	std::cin.ignore();
	if (std::cin.fail()) {
		std::cin.clear();
        while (std::cin.get() != '\n'){
		};
		displayMessage("Invalid input", ERROR_MSG);
		return;
	}
	else if (indexOfContact < 1 || indexOfContact > lastContact){
		displayMessage("Contact not found", SINGLE_MSG);
		return;
	}
	displayMessage("CONTACT DETAILS ", HEADER_MSG);
	_contacts[indexOfContact - 1].displayContact(FULL);
}
