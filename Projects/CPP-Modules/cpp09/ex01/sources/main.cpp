/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:33:05 by tsilva            #+#    #+#             */
/*   Updated: 2026/03/30 10:52:33 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {

    try {
        if (argc != 2 || std::string(argv[1]).empty()) 
            throw std::runtime_error("Error");

        RPN rpn;
        rpn.processExpression(argv[1]);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return (0);
}