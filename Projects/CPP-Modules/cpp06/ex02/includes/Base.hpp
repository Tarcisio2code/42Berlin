/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:29:51 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/12 19:54:32 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base{
    public:
        virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

#endif
