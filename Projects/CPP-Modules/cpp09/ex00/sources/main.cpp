/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:11:14 by tsilva            #+#    #+#             */
/*   Updated: 2026/03/30 10:52:48 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {

    try {
        if (argc != 2 || std::string(argv[1]).empty())
            throw std::runtime_error("Error: could not open file.");

        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInputFile(argv[1]);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }

    return 0;
}
