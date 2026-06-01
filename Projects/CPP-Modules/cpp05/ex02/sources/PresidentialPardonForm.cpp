/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:23:20 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 17:22:05 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("Default President") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other){
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string PresidentialPardonForm::getTarget() const{
	return this->_target;
}

void PresidentialPardonForm::action() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
