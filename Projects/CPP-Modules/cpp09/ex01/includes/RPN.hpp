/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:05:41 by tsilva            #+#    #+#             */
/*   Updated: 2026/04/01 11:00:46 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <list>
#include <string>

class RPN {
private:
    std::stack<int, std::list<int> > _operands;

public:
    RPN();
    RPN(const RPN &source);
    RPN &operator=(const RPN &source);
    ~RPN();

    void processExpression(const std::string &expression);

private:
    void _calculate(char op);
};

#endif