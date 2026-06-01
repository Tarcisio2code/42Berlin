/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:40:28 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/29 16:38:23 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <exception>

class Span
{
    private:
        unsigned int        _capacity;
        std::vector<int>    _container;
        Span(); // to prevent Span without size.

    public:
        Span(unsigned int N);
        Span(const Span &source);
        Span &operator=(const Span &source);
        ~Span();

        void addNumber(int number);

        template <typename Iterator>
        void addRangeOfNumbers(Iterator first, Iterator last){
            if (std::distance(first, last) + _container.size() > _capacity)
                throw CapacityExceeded();
            _container.insert(_container.end(), first, last);
        }

        int shortestSpan() const;
        int longestSpan() const;

        unsigned int getSize() const;

        class CapacityExceeded : public std::exception {
            virtual const char* what() const throw();
        };
        class NoElements : public std::exception {
            virtual const char* what() const throw();
        };
};

#endif