/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 08:40:17 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/15 14:03:38 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOREAUCRAT_HPP
# define BOREAUCRAT_HPP

#include <iostream>
#include <string>

// Forward declaration
class AForm;

class	Bureaucrat{

	private:
		const std::string	_name;
		int					_grade;
		
	public:
		//Default constructor
		Bureaucrat();

		//Parametrized constructor
		Bureaucrat(const std::string &name, int grade);

		//Copy constructor
		Bureaucrat(const Bureaucrat &other);

		//Copy assignment operator overload
		Bureaucrat &operator=(const Bureaucrat &other);

		//Destructor
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);
		void executeForm(const AForm &form) const;

		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw();
		};
};

//Insertion operator overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif