/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:49:14 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/17 10:12:01 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { (void)other; }

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *createShrubberyForm(const std::string &target){
	ShrubberyCreationForm *newForm = new ShrubberyCreationForm(target);
	return newForm;
}

AForm *createRobotomyForm(const std::string &target){
	RobotomyRequestForm *newForm = new RobotomyRequestForm(target);
	return newForm;
}

AForm *createPresidencialForm(const std::string &target){
	PresidentialPardonForm *newForm = new PresidentialPardonForm(target);
	return newForm;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &formTarget) const {
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm *(*formCreators[3])(const std::string &) = { &createShrubberyForm, 
		&createRobotomyForm, &createPresidencialForm };

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](formTarget);
		}
	}

	std::cout << "Intern cannot create form: \"" << formName << "\" (unknown form)" << std::endl;
	return NULL;
}
