/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:22:07 by tsilva            #+#    #+#             */
/*   Updated: 2025/12/15 14:13:10 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "../includes/AForm.hpp"

class Intern{
    public:
        //Default constructor
        Intern();

        //Copy constructor
        Intern(const Intern &other);

        //Copy assignment operator overload
        Intern &operator=(const Intern &other);

        //Destructor
        ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &formTarget) const;
};


#endif