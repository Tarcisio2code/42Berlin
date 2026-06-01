/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:26:00 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/28 17:10:40 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include "../includes/easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int target){
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), target);

    if (it == container.end()){
        throw std::runtime_error("Error: No occurrences found.");
    }
    return it;
}

#endif