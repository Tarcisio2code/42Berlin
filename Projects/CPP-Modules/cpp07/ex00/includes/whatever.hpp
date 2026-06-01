/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:50:32 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/09 17:34:50 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T min(T x, T y){
    if (x < y)
        return x;
    return y;
}

template<typename T>
T max(T x, T y){
    if (x > y)
        return x;
    return y;
}

#endif