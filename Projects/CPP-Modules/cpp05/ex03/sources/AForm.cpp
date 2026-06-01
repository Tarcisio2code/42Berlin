/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:43:30 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/01 16:40:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {

	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed),
	  _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm &AForm::operator=(const AForm &other){
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { 
	return _name; 
}

bool AForm::getSigned() const {
	return _signed; 
}
int AForm::getSignGrade() const { 
	return _signGrade; 
}

int AForm::getExecGrade() const { 
	return _execGrade; 
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!this->getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();

	this->action();
}

const char *AForm::GradeTooHighException::what() const throw(){
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw(){
	return "Grade is too low.";
}

const char *AForm::FormNotSignedException::what() const throw(){
	return "Form not signed";
}

std::ostream &operator<<(std::ostream& out, const AForm &AForm){
	std::string status = "";

	if (AForm.getSigned())
		status = "signed";
	else
		status = "unsigned";
	out << "AForm: " << AForm.getName() 
	<< ", status: " << status 
	<< ", grade required to sign: " << AForm.getSignGrade() 
	<< ", grade required to execute: " << AForm.getExecGrade()
	<< ".";
	return out;
}