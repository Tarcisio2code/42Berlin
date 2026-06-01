/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:43:30 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 11:15:37 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &name, int signGrade, int execGrade) 
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) 
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade),_execGrade(other._execGrade){}

Form &Form::operator=(const Form &other){
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

Form::~Form() {}

const std::string &Form::getName() const{
	return this->_name;
}

bool Form::getSigned() const{
	return this->_signed;
}

int Form::getSignGrade() const{
	return this->_signGrade;
}

int Form::getExecGrade() const{
	return this->_execGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw(){
    return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw(){
    return "Grade is too low.";
}

std::ostream &operator<<(std::ostream& out, const Form &form){
	std::string status = "";

	if (form.getSigned())
		status = "signed";
	else
		status = "unsigned";
	out << "Form: " << form.getName() 
	<< ", status: " << status 
	<< ", grade required to sign: " << form.getSignGrade() 
	<< ", grade required to execute: " << form.getExecGrade()
	<< ".";
	return out;
}