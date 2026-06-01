/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:05:13 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/30 19:00:41 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <ctime>

int main() {
    std::cout << "---- Test: Simple Span ---- " << std::endl;
    try{
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: "  << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---- Test: Big Span (20.000 elements) ----" << std::endl;
    try {
        Span bigSpan(20000);
        std::vector<int> bigData;
        std::srand(std::time(0));
        for (int i = 0; i < 20000; ++i)
            bigData.push_back(std::rand());

        bigSpan.addRangeOfNumbers(bigData.begin(), bigData.end());

        std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest: "  << bigSpan.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---- Test: Insufficient elements ----" << std::endl;
    try{
        Span smallSpan = Span(1);
        smallSpan.addNumber(42);
        int shortest = smallSpan.shortestSpan();
        std::cout << "Shortest: " << shortest << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---- Test: Deep Copy & Capacity Integrity ----" << std::endl;
    try{
        Span originalSpan(2);
        originalSpan.addNumber(1);

        Span copySpan = originalSpan;
        copySpan.addNumber(2);
        std::cout << "Original container size : " << originalSpan.getSize() << std::endl;
        std::cout << "Copy container size     : " << copySpan.getSize() << std::endl;
        std::cout << std::endl;
        copySpan.addNumber(3);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

