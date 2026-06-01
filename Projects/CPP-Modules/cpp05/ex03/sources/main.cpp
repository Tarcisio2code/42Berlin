/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:33:23 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/17 10:54:24 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"
#include <ctime>

int main(){

	try{
		std::cout << "\n[ Bureaucrats ]" << std::endl;
		Bureaucrat boss("Vader", 5);
		std::cout << boss << std::endl;

		std::cout << "\n[ Shrubbery Form ]" << std::endl;
		Intern aRandomIntern;
		AForm *scf;
		scf = aRandomIntern.makeForm("shrubbery creation", "Planet42");
		if (scf){
			boss.signForm(*scf);
			boss.executeForm(*scf);
			std::cout << *scf << std::endl;
			delete scf;
		}

		std::cout << "\n[ Robotomy Form ]" << std::endl;
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "C-3PO");
		if (rrf){
			boss.signForm(*rrf);
			std::srand(std::time(NULL));
			boss.executeForm(*rrf);
			std::cout << *rrf << std::endl;
			delete rrf;
		}

		std::cout << "\n[ Presidential Form ]" << std::endl;
		Intern anotherRandomIntern;
		AForm *ppf;
		ppf = anotherRandomIntern.makeForm("presidential pardon", "Intern");
		if (ppf){
			boss.signForm(*ppf);
			boss.executeForm(*ppf);
			std::cout << *ppf << std::endl;
			delete ppf;
		}

		std::cout << "\n[ Incorrect form name ]" << std::endl;
		Intern rookieIntern;
		AForm *f;
		f = rookieIntern.makeForm("advance vacation request for inters!", "relax");
		if (f){
			boss.signForm(*f);
			boss.executeForm(*f);
			std::cout << *f << std::endl;
			delete f;
		}
	} catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
