/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilva <tsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:36:44 by tsilva            #+#    #+#             */
/*   Updated: 2026/03/27 12:42:36 by tsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
    private:
        std::map<std::string, double> _exchangeRates;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange &operator=(const BitcoinExchange &source);
        ~BitcoinExchange();

        void loadDatabase(const std::string &filename);
        void processInputFile(const std::string &filename);

    private:
        double findExchangeRate(const std::string &date) const;
};

#endif
