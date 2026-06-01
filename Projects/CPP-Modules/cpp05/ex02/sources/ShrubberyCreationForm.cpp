/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:42:30 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 17:22:16 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Default Shrubbery") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other._target;
	}		
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::action() const {
	std::string fileName = _target + "_shrubbery";
	std::ofstream targetFile(fileName.c_str());

	if (targetFile.is_open()) {
		targetFile << "      /\\      " << std::endl;
		targetFile << "     /\\*\\     " << std::endl;
		targetFile << "    /\\O\\*\\    " << std::endl;
		targetFile << "   /\\/\\/\\/\\   " << std::endl;
		targetFile << "  /\\*\\O\\/\\*\\  " << std::endl;
		targetFile << " /\\O\\/\\*\\/\\/\\" << std::endl;
		targetFile << "      ||      " << std::endl;
		targetFile << "      ||      " << std::endl;
		targetFile << "     ||||      " << std::endl;
		targetFile.close();
	} else {
        throw std::runtime_error("The file could not be opened.");
	}
}