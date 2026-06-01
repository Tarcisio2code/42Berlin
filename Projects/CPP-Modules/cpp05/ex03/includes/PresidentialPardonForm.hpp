/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:22:18 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 17:20:22 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "../includes/AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;

	public:
		//Default constructor
		PresidentialPardonForm();

		//Parametrized constructor
		PresidentialPardonForm(const std::string &target);

		//Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm &other);

		//Copy assignment operator overload
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		//Destructor
		~PresidentialPardonForm();

		std::string getTarget() const;
		
		void action() const;
};

#endif