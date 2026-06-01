/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:54:04 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/11 12:58:26 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>

template <typename T>
class Array{

    private:
        T               * _elements;
        unsigned int    _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfBoundsException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "../includes/Array.tpp"

#endif