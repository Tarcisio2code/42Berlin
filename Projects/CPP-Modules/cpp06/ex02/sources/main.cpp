/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:56:20 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/12 19:55:51 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/Functions.hpp"

int main(){
	std::srand(std::time(NULL));

    for (int i = 0; i < 3; i++){
        Base *instance = generate();

        std::cout << "Instance " << i + 1 << std::endl;
        std::cout << "  Pointer: ";
        identify(instance);
        std::cout << "  Reference: ";
        identify(*instance);

        delete instance;
    }

    std::cout << "\nPure Base object..." << std::endl;
    Base invalid;
    identify(&invalid);
    identify(invalid);
    return 0;
}
