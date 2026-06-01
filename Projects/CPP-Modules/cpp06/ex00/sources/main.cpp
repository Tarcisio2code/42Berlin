/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 13:38:22 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/12 19:51:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int ac, char **av){
    if (ac != 2)
    {
        std::cerr << "Invalid entry!\nUsage: ./convert <literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}

