/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:23:59 by tsilva            #+#    #+#             */
/*   Updated: 2026/03/29 09:05:54 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>

int main(int argc, char **argv) {   
    try {
        if (argc < 2) 
            throw std::runtime_error("Error");

        PmergeMe sorter(argc, argv);
        sorter.process();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
