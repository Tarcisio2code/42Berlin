/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 08:40:29 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/15 13:56:08 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    if (this != &other){
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::getName() const{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->_grade;
}

void Bureaucrat::incrementGrade(){
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b){
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}