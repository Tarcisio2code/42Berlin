/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:38:54 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 17:20:22 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "../includes/AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;

	public:
		//Default constructor
		ShrubberyCreationForm();

		//Parametrized constructor
		ShrubberyCreationForm(const std::string &target);

		//Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &other);

		//Copy assignment operator overload
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

		//Destructor
		~ShrubberyCreationForm();

		std::string getTarget() const;
		
		void action() const;
};

#endif