/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:33:23 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 17:32:06 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <ctime>

int main(){

	try{
		std::cout << "\n[ Bureaucrats ]" << std::endl;
		Bureaucrat boss("Vader", 10);

		std::cout << boss << std::endl;

		std::cout << "\n[ Shrubbery ]" << std::endl;
		ShrubberyCreationForm Shrubbery("Garden");
		std::cout << Shrubbery << std::endl;
		std::cout << "Try to execute an unsigned Form...." << std::endl;
		boss.executeForm(Shrubbery);
		std::cout << "Try signing the Form...." << std::endl;
		boss.signForm(Shrubbery);
		std::cout << "Try to execute the Form...." << std::endl;
		boss.executeForm(Shrubbery);
		std::cout << Shrubbery << std::endl;

		std::cout << "\n[ Robotomy ]" << std::endl;
		RobotomyRequestForm Robot("R2D2");
		std::cout << Robot << std::endl;
		std::cout << "Try to execute an unsigned Form...." << std::endl;
		boss.executeForm(Robot);
		std::cout << "Try signing the Form...." << std::endl;
		boss.signForm(Robot);
		std::cout << "Try to execute the Form...." << std::endl;
		std::srand(std::time(NULL));
		boss.executeForm(Robot);
		std::cout << Robot << std::endl;
		std::cout << "\n[ Presidential ]" << std::endl;
		PresidentialPardonForm presidencial("Boss");
		std::cout << presidencial << std::endl;
		std::cout << "Try to execute an unsigned Form...." << std::endl;		
		boss.executeForm(presidencial);
		std::cout << "Try signing the Form...." << std::endl;
		boss.signForm(presidencial);
		std::cout << "Try to execute the Form...." << std::endl;
		boss.executeForm(presidencial);
		std::cout << presidencial << std::endl;

	} catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
