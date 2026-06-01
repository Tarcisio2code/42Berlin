/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:45:59 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/20 11:03:31 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <cstddef>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &)){
    if (!array || !f)
        return;

    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template <typename T>
void iter(const T *array, size_t length, void (*f)(const T &)){
    if (!array || !f)
        return;

    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif