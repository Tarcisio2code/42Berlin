/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:08:09 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 17:32:48 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "../includes/AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;

	public:
		//Default constructor
		RobotomyRequestForm();

		//Parametrized constructor
		RobotomyRequestForm(const std::string &target);

		//Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm &other);

		//Copy assignment operator overload
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		//Destructor
		~RobotomyRequestForm();

		std::string getTarget() const;

		void action() const;
};

#endif