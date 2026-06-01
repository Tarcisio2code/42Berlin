/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 18:21:18 by tsilva            #+#    #+#             */
/*   Updated: 2026/04/02 12:05:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <limits>
#include <iomanip>

PmergeMe::PmergeMe(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        long value = parseArgument(argv[i]);
        _containerVector.push_back(value);
        _containerDeque.push_back(value);
    }
}

PmergeMe::PmergeMe(const PmergeMe &source) {
    *this = source;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source) {
    if (this != &source) {
        _containerVector = source._containerVector;
        _containerDeque = source._containerDeque;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

long PmergeMe::parseArgument(char *arg) {
    if (!arg || *arg == '\0' || *arg == '-')
        throw std::runtime_error("Error");

    char *end = NULL;
    long value = std::strtol(arg, &end, 10);
    if (*end || value > std::numeric_limits<int>::max())
        throw std::runtime_error("Error");
    return (value);
}

template<typename T>
void PmergeMe::printContainer(T &container){

    size_t limit = 10;
    size_t last = std::min(container.size(), limit);

    std::copy(container.begin(), container.begin() + last,
              std::ostream_iterator<typename T::value_type>(std::cout, " "));

    if (container.size() > limit)
        std::cout << "[...]";

    std::cout << std::endl;
}

// Jn = J(n-1) + 2*J(n-2)
std::vector<size_t> PmergeMe::getJacobsthalNumbers(size_t pendSize)
{
    std::vector<size_t> jacob;

    jacob.push_back(0);
    jacob.push_back(1);

    while (jacob.back() < pendSize)
    {
        size_t size = jacob.size();
        jacob.push_back(jacob[size - 1] + 2 * jacob[size - 2]);
    }

    return jacob;
}

struct Pair {
    int smaller;
    int larger;
};

//fordJohnson
void PmergeMe::mergeInsertionSortVector(std::vector<int> &vector) {
    if (vector.size() <= 1) 
        return;

    // 1) Pairing
    std::vector<Pair> pairs;
    size_t i = 0;
    for (; i + 1 < vector.size(); i += 2) {
        if (vector[i] < vector[i + 1])
            pairs.push_back((Pair){vector[i], vector[i + 1]});
        else
            pairs.push_back((Pair){vector[i + 1], vector[i]});
    }

    // element without a pair.
    int leftover = -1;
    bool hasLeftover = (i < vector.size());
    if (hasLeftover) 
        leftover = vector[i];

    // Sort largest elements
    std::vector<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j) {
        mainChain.push_back(pairs[j].larger);
    }
    
    mergeInsertionSortVector(mainChain);

    // new list of pairs based on the order of mainChain, to maintain the connection between the pairs.
    std::vector<Pair> matchedPairs;
    for (size_t j = 0; j < mainChain.size(); ++j) {
        for (std::vector<Pair>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->larger == mainChain[j]) {
                matchedPairs.push_back(*it);
                pairs.erase(it);
                break;
            }
        }
    }

    // Build Pend (smallest)
    std::vector<int> pend;
    for (size_t j = 0; j < matchedPairs.size(); ++j) {
        pend.push_back(matchedPairs[j].smaller);
    }

    // Insert the first smallest
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    // Jacobsthal
    std::vector<size_t> jacobIdx = getJacobsthalNumbers(pend.size());

    size_t insertions = 1;
    for (size_t j = 2; j < jacobIdx.size(); ++j) {
        size_t limit = std::min(jacobIdx[j], pend.size());
        size_t prev = jacobIdx[j - 1];

        for (size_t k = limit; k > prev; --k) {
            if (k - 1 >= pend.size())
                continue;

            int itemToInsert = pend[k - 1];
            // looking for the current position of the corresponding "largest" pair.
            std::vector<int>::iterator endIt = std::find(mainChain.begin(), mainChain.end(), matchedPairs[k - 1].larger);
            size_t pairPositon = std::distance(mainChain.begin(), endIt);

            std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + pairPositon, itemToInsert);
            mainChain.insert(pos, itemToInsert);

            ++insertions;
        }
        if (insertions >= pend.size())
            break;
    }

    // insert Leftover
    if (hasLeftover) {
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), leftover), leftover);
    }

    vector = mainChain;
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &deque)
{
    if (deque.size() <= 1) 
        return;

    // 1) Pairing
    std::deque<Pair> pairs;
    size_t i = 0;
    for (; i + 1 < deque.size(); i += 2) {
        if (deque[i] < deque[i + 1])
            pairs.push_back((Pair){deque[i], deque[i + 1]});
        else
            pairs.push_back((Pair){deque[i + 1], deque[i]});
    }

    // element without a pair.
    int leftover = -1;
    bool hasLeftover = (i < deque.size());
    if (hasLeftover) 
        leftover = deque[i];

    // Sort largest elements
    std::deque<int> mainChain;
    for (size_t j = 0; j < pairs.size(); ++j) {
        mainChain.push_back(pairs[j].larger);
    }
    
    mergeInsertionSortDeque(mainChain);

    // new list of pairs based on the order of mainChain, to maintain the connection between the pairs.
    std::deque<Pair> matchedPairs;
    for (size_t j = 0; j < mainChain.size(); ++j) {
        for (std::deque<Pair>::iterator it = pairs.begin(); it != pairs.end(); ++it) {
            if (it->larger == mainChain[j]) {
                matchedPairs.push_back(*it);
                pairs.erase(it);
                break;
            }
        }
    }

    // Build Pend (smallest)
    std::deque<int> pend;
    for (size_t j = 0; j < matchedPairs.size(); ++j) {
        pend.push_back(matchedPairs[j].smaller);
    }

    // Insert the first smallest
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    // Jacobsthal
    std::vector<size_t> jacobIdx = getJacobsthalNumbers(pend.size());

    size_t insertions = 1;
    for (size_t j = 2; j < jacobIdx.size(); ++j) {
        size_t limit = std::min(jacobIdx[j], pend.size());
        size_t prev = jacobIdx[j - 1];

        for (size_t k = limit; k > prev; --k) {
            if (k - 1 >= pend.size())
                continue;

            int itemToInsert = pend[k - 1];
            // looking for the current position of the corresponding "largest" pair.
            std::deque<int>::iterator endIt = std::find(mainChain.begin(), mainChain.end(), matchedPairs[k - 1].larger);
            size_t pairPositon = std::distance(mainChain.begin(), endIt);

            std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.begin() + pairPositon, itemToInsert);
            mainChain.insert(pos, itemToInsert);

            ++insertions;
        }
        if (insertions >= pend.size())
            break;
    }

    // insert Leftover
    if (hasLeftover) {
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), leftover), leftover);
    }

    deque = mainChain;
}

void PmergeMe::printStatistics(std::string type, std::size_t size, double time){
    std::cout << "Time to process a range of " << size
              << " elements with " << type << " : " << std::fixed << std::setprecision(6) << time << " us" << std::endl;
}

void PmergeMe::process() {
    std::cout << "Before: ";
    printContainer(this->_containerVector);

    std::vector<int> vectorCopy = _containerVector;
    std::deque<int> dequeCopy = _containerDeque;

    std::clock_t timeBeforeVector = std::clock();
    mergeInsertionSortVector(vectorCopy);
    std::clock_t timeAfterVector = std::clock();

    std::clock_t timeBeforeDeque = std::clock();
    mergeInsertionSortDeque(dequeCopy);
    std::clock_t timeAfterDeque = std::clock();

    std::cout << "After: ";
    printContainer(vectorCopy);
    double timeVector = static_cast<double>(timeAfterVector - timeBeforeVector) / CLOCKS_PER_SEC;
    printStatistics("std::vector", vectorCopy.size(), timeVector);
    double timeDeque = static_cast<double>(timeAfterDeque - timeBeforeDeque) / CLOCKS_PER_SEC;
    printStatistics("std::deque", dequeCopy.size(), timeDeque);
}
