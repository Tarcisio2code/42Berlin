/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:49:36 by tsilva            #+#    #+#             */
/*   Updated: 2026/03/27 18:55:35 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source) {
    *this = source;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source) {
    if (this != &source)
        _exchangeRates = source._exchangeRates;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void removeWhitespace(std::string &str){
    const char* whitespace = " \t\n\r\f\v";
    
    size_t begin = str.find_first_not_of(whitespace);
    if (begin == std::string::npos) {
        str.clear();
        return ;
    }
    str.erase(0, begin);
    str.erase(str.find_last_not_of(whitespace) + 1);
}

bool hasOnlyDigit(std::string &str){
    if (str.empty())
        return (false);

    for (size_t i = 0; i < str.length(); i++){
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

std::string parseDate(std::stringstream &ss, char delimiter) {
    std::string yearStr, monthStr, dayStr;
    const char* whitespace = " \t\n\r\f\v";
    
    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
    std::getline(ss, dayStr, delimiter);

    yearStr.erase(0, yearStr.find_first_not_of(whitespace));
    dayStr.erase(dayStr.find_last_not_of(whitespace) + 1);

    if (yearStr.size() != 4 || !hasOnlyDigit(yearStr) || !hasOnlyDigit(monthStr) || !hasOnlyDigit(dayStr))
        return ("");

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    int validDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        validDays[1] = 29;

    if (year < 2009 || month < 1 || month > 12 || day < 1 || day > validDays[month - 1])
        return ("");

    std::stringstream normalized;
    normalized << yearStr << "-"
                << std::setw(2) << std::setfill('0') << monthStr << "-"
                << std::setw(2) << std::setfill('0') << dayStr;
    return (normalized.str());
}

bool parseValue(std::stringstream &ss, double &value) {
    std::string valueStr;
    double newValue;

    if (!std::getline(ss, valueStr))
        return (false);

    removeWhitespace(valueStr);

    char *end;
    newValue = std::strtod(valueStr.c_str(), &end);
    if (*end == 'f')
        end++;
    if (*end != '\0')
        return (false);

    value = newValue;

    return (true);
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream database(filename.c_str());
    std::string line;

    if (!database.is_open() || database.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: database could not be opened or it is empty.");
    
    std::getline(database, line);
    while (std::getline(database, line)) {
        std::stringstream ss(line);
        std::string date = parseDate(ss, ',');
        double value;

        if (date.empty() || !parseValue(ss, value))
            continue;

        _exchangeRates[date] = value;
    }
    if (_exchangeRates.size() == 0)
        throw std::runtime_error("Error: invalid database.");
}

void BitcoinExchange::processInputFile(const std::string &filename) {
    std::ifstream inputFile(filename.c_str());
    std::string line;

    if (!inputFile.is_open() || inputFile.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Error: input file could not be opened or it is empty.");

    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string date = parseDate(ss, '|');
        double value;
        if (date.empty() || !parseValue(ss, value)){
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        try {
            double rate = findExchangeRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}

double BitcoinExchange::findExchangeRate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it != _exchangeRates.end() && it->first == date)
        return it->second;
    if (it == _exchangeRates.begin())
        throw std::runtime_error("Error: no lower date available.");
    --it;
    return (it->second);
}

