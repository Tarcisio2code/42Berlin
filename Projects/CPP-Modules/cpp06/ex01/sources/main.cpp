/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:13:18 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/12 19:53:42 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main (){
    Data newData;

    newData.value = 42;
    Data *ptrOrigin = &newData;
    uintptr_t serialized = Serializer::serialize(ptrOrigin);
    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "Original Address:     " << ptrOrigin << ", value: " << ptrOrigin->value << std::endl;
    std::cout << "Serialized:           " << serialized << std::endl;
    std::cout << "Deserialized Address: " << deserialized << ", value: " << deserialized->value << std::endl;
}
