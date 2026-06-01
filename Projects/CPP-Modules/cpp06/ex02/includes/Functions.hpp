/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:41:22 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/08 11:18:57 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

#include "../includes/Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void);

void identify(Base *p);

void identify(Base &p);

#endif