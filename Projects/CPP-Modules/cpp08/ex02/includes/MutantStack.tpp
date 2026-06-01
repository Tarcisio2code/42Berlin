/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 11:41:55 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/30 16:55:49 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "../includes/MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &source) : std::stack<T>(source) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &source) {
    if (this != &source) {
        std::stack<T>::operator=(source);
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { 
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { 
    return this->c.end(); 
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { 
    return this->c.begin(); 
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { 
    return this->c.end(); 
}

#endif