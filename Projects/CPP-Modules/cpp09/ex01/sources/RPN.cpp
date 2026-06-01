/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:09:05 by tsilva            #+#    #+#             */
/*   Updated: 2026/04/01 12:09:15 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <limits>

RPN::RPN() {}

RPN::RPN(const RPN &source) {
    *this = source;
}

RPN &RPN::operator=(const RPN &source) {
    if (this != &source)
        _operands = source._operands;
    return (*this);
}

RPN::~RPN() {}

bool _isOperator(const char &token){
    std::string operators = "+-/*";
    return (operators.find(token) != std::string::npos);
}

void RPN::_calculate(char op) {
    if (_operands.size() < 2)
        throw std::runtime_error("Error");

    long b = _operands.top();
    _operands.pop();
    long a = _operands.top();
    _operands.pop();
    long r = 0;
    
    if (op == '+')
        r = a + b;
    else if (op == '-')
        r = a - b;
    else if (op == '*')
        r = a * b;
    else if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Error");
        r = a / b;
    }

    if (r > std::numeric_limits<int>::max() || r < std::numeric_limits<int>::min())
        throw std::runtime_error("Error");

    _operands.push(static_cast<int>(r));
    
}

void RPN::processExpression(const std::string &expression) {
    std::stringstream ss(expression);

    std::string token;
    while (ss >> token) {
        if (token.length() == 1 && std::isdigit(token[0]))
            _operands.push(token[0] - '0');
        else if (token.length() == 1 && _isOperator(token[0])){
            _calculate(token[0]);
        }
        else
            throw std::runtime_error("Error");
    }
    
    if (_operands.size() != 1)
        throw std::runtime_error("Error");

    std::cout << _operands.top() << std::endl;
}
