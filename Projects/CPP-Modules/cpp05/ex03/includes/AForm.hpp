/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:19:26 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/15 14:10:20 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		//Default constructor
		AForm();

		//Parametrized constructor
		AForm(const std::string &name, int signGrade, int execGrade);

		//Copy constructor
		AForm(const AForm &other);

		//Copy assignment operator overload
		AForm &operator=(const AForm &other);

		//Destructor
		virtual ~AForm();

		const std::string &getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		virtual void action() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

//Insertion operator overload
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif