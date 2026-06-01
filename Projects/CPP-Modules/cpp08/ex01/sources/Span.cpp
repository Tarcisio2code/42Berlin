/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:53:56 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/30 19:00:22 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _capacity(N) {}

Span::Span(const Span &source) : _capacity(source._capacity), 
                                 _container(source._container) {}

Span &Span::operator=(const Span &source)
{
    if (this != &source)
    {
        this->_capacity = source._capacity;
        this->_container = source._container;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_container.size() >= _capacity)
        throw CapacityExceeded();
    _container.push_back(number);
}

int Span::shortestSpan() const
{
    if (_container.size() < 2)
        throw NoElements();

    std::vector<int> tmpContainer = _container;
    std::sort(tmpContainer.begin(), tmpContainer.end());

    int minDiff = tmpContainer[1] - tmpContainer[0];
    for (size_t i = 1; i < tmpContainer.size() - 1; ++i) {
        int diff = tmpContainer[i + 1] - tmpContainer[i];
        if (diff < minDiff)
            minDiff = diff;
    }
    return (minDiff);
}

int Span::longestSpan() const
{
    if (_container.size() < 2)
        throw NoElements();

    std::vector<int> tmpContainer = _container;
    std::sort(tmpContainer.begin(), tmpContainer.end());

    return (tmpContainer.back() - tmpContainer.front());
}

unsigned int Span::getSize() const{
    return this->_container.size();
};

const char* Span::CapacityExceeded::what() const throw() {
    return "Exception: storage limit exceeded.";
}

const char* Span::NoElements::what() const throw() {
    return "Exception: Not enough elements.";
}
