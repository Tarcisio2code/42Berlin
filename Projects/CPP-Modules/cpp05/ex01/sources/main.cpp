/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:33:23 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 11:28:02 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

int main(){

	try{
		std::cout << "\n[ Bureaucrats ]" << std::endl;
		Bureaucrat a("Lea", 30);
		Bureaucrat b("Luck", 10);
		Bureaucrat c("Vader", 5);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		std::cout << "\n[ Forms ]" << std::endl;
		Form meetingForm("Meeting Request", 50, 100);
		Form vacationForm("Vacation Authorization", 5, 10);
		std::cout << meetingForm << std::endl;
		std::cout << vacationForm << std::endl;
		std::cout << std::endl;

		a.signForm(meetingForm);
		b.signForm(meetingForm);
		c.signForm(vacationForm);
		std::cout << std::endl;

		a.signForm(vacationForm);
		b.signForm(vacationForm);
		std::cout << std::endl;

		std::cout << meetingForm << std::endl;
		std::cout << vacationForm << std::endl;

	}  catch(const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
