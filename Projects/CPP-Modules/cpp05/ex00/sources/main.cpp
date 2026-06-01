/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:33:23 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/16 14:00:14 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main(){
    try{
        std::cout << "\n[ Bureaucrats ]" << std::endl; 
        Bureaucrat a("Lea", 3);
        Bureaucrat b("Luck", 149);

        std::cout << a << std::endl;
        std::cout << b << std::endl;
        
        std::cout << "\nIncrementing..." << std::endl;
        a.incrementGrade();
        std::cout << a << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;

        std::cout << "\nDecrementing..." << std::endl;
        a.decrementGrade();
        std::cout << a << std::endl;
        b.decrementGrade();
        b.decrementGrade();
        std::cout << b << std::endl;

        std::cout << "\nTrying to decrement " << b.getName() << std::endl;
        b.decrementGrade();
    } catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}
    return 0;
}
