/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:36:17 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/17 15:04:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Main execution loop of the PhoneBook program.
 * * OBJECTIVE: 
 * This function initializes the PhoneBook, displays a welcome message, 
 * and enters a continuous loop to process user commands: ADD, SEARCH, and EXIT.
 * It also handles potential input stream errors or EOF (End-of-File) conditions.
 * * @return int Returns 0 upon successful completion.
 */

#include "PhoneBook.hpp"

int main(){

	PhoneBook phonebook;
	std::string inputOption;

	phonebook.displayMessage("WELCOME TO THE AWESOME PHONEBOOK", GREETING_MSG);

	do {
		phonebook.displayMenu();
		// Handle user input and check for EOF (Ctrl+D) or stream failures
		if (!std::getline(std::cin, inputOption)) {
			phonebook.displayMessage("Input error or EOF detected. Exiting.", ERROR_MSG);
			break;
		}
		if (inputOption.compare("EXIT") == 0)
			break ;
		else if (inputOption.compare("ADD") == 0)
			phonebook.addContact();
		else if (inputOption.compare("SEARCH") == 0)
			phonebook.searchContact();
		else
			phonebook.displayMessage("Invalid option", ERROR_MSG);
	} while (true);

	return 0;
}
