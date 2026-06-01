/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:24:12 by tsilva            #+#    #+#             */
/*   Updated: 2026/03/06 15:14:43 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> _containerVector;
    std::deque<int>  _containerDeque;

public:
    PmergeMe(int argc, char **argv);
    PmergeMe(const PmergeMe &source);
    PmergeMe &operator=(const PmergeMe &source);
    ~PmergeMe();

    void process();

private:
    long parseArgument(char *arg);

    void printStatistics(std::string type, std::size_t size, double time);

    template<typename T>
    void printContainer(T &container);

    std::vector<size_t> getJacobsthalNumbers(size_t n);
    void mergeInsertionSortVector(std::vector<int> &container);
    void mergeInsertionSortDeque(std::deque<int> &container);
};

#endif