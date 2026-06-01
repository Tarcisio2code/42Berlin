/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:42:49 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/12 19:54:00 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const  Serializer &other) { (void) other; }

Serializer& Serializer::operator=(const  Serializer &other) {
     (void) other;
    return (*this); 
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data *Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*> (raw));
}