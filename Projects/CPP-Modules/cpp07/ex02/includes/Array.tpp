/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 11:54:04 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/20 11:05:41 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "../includes/Array.hpp"

template <typename T>
Array<T>::Array() : _elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _elements(NULL), _size(n){
    if (n > 0)
        _elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &other) : _elements(NULL), _size(other._size){
    if (_size > 0){
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = other._elements[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other){
    if (this != &other){
        _size = other._size;
        delete[] _elements;
        _elements = NULL;
        
        if (_size > 0){
            _elements = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = other._elements[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array(){
    delete[] _elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
    if (index >= _size)
        throw OutOfBoundsException();
    return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
    if (index >= _size)
        throw OutOfBoundsException();
    return _elements[index];
}

template <typename T>
unsigned int Array<T>::size() const{
    return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw(){
    return "Array index out of bounds!";
}

#endif