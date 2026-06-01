/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:19:26 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/15 13:56:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "../includes/Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

	public:
		//Default constructor	
		Form();

		//Parametrized constructor
		Form(const std::string &name, int signGrade, int execGrade);

		//Copy constructor
		Form(const Form &other);

		//Copy assignment operator overload
		Form &operator=(const Form &other);

		//Destructor
		~Form();

		const std::string &getName() const;
		bool getSigned() const;

		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);

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
std::ostream &operator<<(std::ostream& out, const Form &form);

#endif