/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:30:48 by tsilva            #+#    #+#             */
/*   Updated: 2026/01/12 19:52:25 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool validateLiteral(std::string literal){
    if (literal.empty() || literal.find(' ') != std::string::npos)
        return false;
    if (literal.length() > 1){
        char *garbage;
        (void)strtod(literal.c_str(), &garbage);
        if (*garbage && std::string(garbage) != "f")
            return false;
    }
    return true;
}

static void displayChar(double value){
    std::cout << "char: ";
    if(std::isnan(value) || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else   
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void displayInt(double value){
    std::cout << "int: ";
    if(std::isnan(value) || value < INT_MIN || value > INT_MAX)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;
}


static void displayFloat(double value){
    std::cout << "float: " << std::fixed << std::setprecision(1);
    std::cout << static_cast<float>(value) << "f" << std::endl;
}

static void displayDouble(double value){
    std::cout << "double: " << std::fixed << std::setprecision(1);
    std::cout << value << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
    double value;

    if(!validateLiteral(literal)){
        std::cout << "Invalid literal type, conversion is impossible" << std::endl;
        return ;
    }
    if (literal.length() == 1 && !isdigit(literal[0]))
    	value = static_cast<double>(literal[0]);
	else
		value = strtod(literal.c_str(), NULL); 

    displayChar(value);
    displayInt(value);
    displayFloat(value);
    displayDouble(value);
}
